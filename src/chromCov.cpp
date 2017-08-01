#include "api/BamReader.h"
#include "api/BamWriter.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
using namespace BamTools;
using namespace std;
int main(int argc, char *argv[])
{
	const string splash="chromCov calculate coverage for each chromosome\nVersion: 1.0	Author: Danny Antaki <dantaki@ucsd.edu>\n\n"
				"Usage: chromCov -i <in.bam> -q <INT> -o <output.txt>\n\nOptions:\n"
				"    -i        Input: BAM filename\n    -q        Mapping quality threshold [10]\n    -o        Output: filename\n\n";
	string ifh; 
	string ofh;
	int Q=10;
	if ( (argc==1) ||
	     (argc==2 && string(argv[1]) == "-h") ||
	     (argc==2 && string(argv[1]) == "-help") ||
	     (argc==2 && string(argv[1]) == "--help")) {
		cout << "" << endl; cout << splash << endl;
		return 1;
	}
	for(int i=1; i<argc; i++){
		if(string(argv[i]) == "-i" || string(argv[i]) == "--in" || string(argv[i]) == "-in"){ ifh = string(argv[i+1]); i++; continue; }
		if(string(argv[i]) == "-o" || string(argv[i]) == "--out" || string(argv[i]) == "-out"){ ofh = string(argv[i+1]); i++; continue; }
		if(string(argv[i]) == "-q" || string(argv[i]) == "--q"){ Q = atoi(argv[i+1]); i++; continue; }
		cerr << "ERROR: Unknown option "<<string(argv[i])<< endl;
		return 1;
	}
	if(ifh == "") { cerr << "ERROR: No BAM file given\n\n"<< splash << endl; return 1; }
	if(ofh == ""){ ofh = ifh.substr(0,ifh.find_last_of('.'))+"_chromCov.txt";  }		
	map<int32_t, map<int,int> > COV;
	map<int32_t, int32_t> READ;
	BamReader reader;
	if (!reader.Open(ifh)){ cerr << "ERROR: " << ifh << " could not be opened!\n\n"<< splash << endl; return 1; }
	BamAlignment al;
	const RefVector refs = reader.GetReferenceData();
	while (reader.GetNextAlignmentCore(al)){
		if(al.MapQuality < Q || al.IsMapped()==false){ continue; } 	
		unsigned int rlen=0;
		vector<CigarOp> cigar = al.CigarData;
		for(vector<CigarOp>::iterator it= cigar.begin(); it != cigar.end(); ++it){
			if (it->Type == 'M' || it->Type == '=' || it->Type== 'X') { rlen+=it->Length;}	
		}
		if(rlen!=0){ READ[al.RefID]++; COV[al.RefID][rlen]++;}
	}
	reader.Close();
	ofstream fout;
	fout.open (ofh.c_str());	
	fout << "CONTIG\tCOVERAGE\tAVERAGE_READ_LENGTH\tN_READS" << endl;
	uint64_t genSum=0; uint64_t genFreq=0; uint64_t genLen=0; uint64_t genRead=0; 
	for(map<int32_t, map<int,int> >::iterator i=COV.begin(); i != COV.end(); ++i){
		int32_t sum=0; int32_t freq=0; 
		for(map<int,int>::iterator j=COV[(*i).first].begin(); j != COV[(*i).first].end(); ++j){
			sum+= (*j).first * (*j).second;
			freq+=(*j).second;
		}
		genSum+=sum; genFreq+=freq; genLen+=refs[(*i).first].RefLength; genRead+= READ[(*i).first]; 
		double readLen=sum/(double)freq;
		double cov=(READ[(*i).first]*readLen)/(double)refs[(*i).first].RefLength;
		fout << refs[(*i).first].RefName << '\t' << cov << '\t' << readLen <<  '\t' << READ[(*i).first] << endl;
	}
	double genReadLen = genSum/(double)genFreq;
	fout << "GENOME\t" << (genRead*genReadLen)/(double)genLen << '\t' << genReadLen << '\t' << genRead << endl;
	fout.close();
	return 0;
}
