/*
 * Dictionary.h
 *
 *  Created on: 3 mars 2016
 *      Author: younes
 */

#ifndef DICTIONARY_H_
#include <vector>

#define DICTIONARY_H_

using namespace std;


class Dictionary :public Image{
public:
	int k_db;
int number_of_view;
	Mat points_db;
	Dictionary(Dictionary &ob);
	Dictionary(int,int);
	virtual ~Dictionary();
	int clusterKmean();
//	getClasses();

	vector<IplImage*> load_image_db();
};



#endif /* DICTIONARY_H_ */
