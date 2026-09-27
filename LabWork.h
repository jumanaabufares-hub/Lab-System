
#ifndef LABTEST_H
#define LABTEST_H

#include <iostream>
#include <string>


using namespace std;

enum LabWorkCode {BLOOD_TEST, URINE_TEST, XRAY, MRI, CT_SCAN, ULTRASOUND, BIOPSY, GENETIC_TEST, ALLERGY_TEST, COVID19_TEST, NUM_LABTESTS};


class LabWork {
	public:
		
		LabWork(LabWorkCode labWorkCode, double cost);
		static const string LABTESTS[NUM_LABTESTS]; //NUM_LABTESTS is part of the enum LabWorkCode
		static const string NOTCOMPLETE;
		bool isComplete() const;
		void completeLabWork(const string& labTechId);
		void print()const;
	private:
		// add private members
		LabWorkCode labWorkCode;
		double cost;
		string labTechId;
		
};
#endif