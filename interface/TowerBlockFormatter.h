#ifndef TOWERBLOCKFORMATTER_H
#define TOWERBLOCKFORMATTER_H

#include <iostream>
#include <vector>
#include <map>

#include "DataFormats/EcalDigi/interface/EcalDigiCollections.h"
#include "DataFormats/FEDRawData/interface/FEDRawDataCollection.h"
#include "DataFormats/FEDRawData/interface/FEDRawData.h"
#include "EventFilter/EcalDigiToRaw/interface/BlockFormatter.h"

#include "Geometry/EcalMapping/interface/EcalElectronicsMapping.h"


// 
// The crystals corresponding to a given FE in a given FED
//

using namespace std;


class TowerBlockFormatter : public BlockFormatter {
 public :

	TowerBlockFormatter();
	~TowerBlockFormatter();
        static const int kCardsPerTower = 5;     // Number of VFE cards per trigger tower
        void DigiToRaw(const EBDataFrame& dataframe, FEDRawData& rawdata, const EcalElectronicsMapping* TheMapping);
        void DigiToRaw(const EEDataFrame& dataframe, FEDRawData& rawdata, const EcalElectronicsMapping* TheMapping);
	void StartEvent();
	void EndEvent(FEDRawDataCollection* productRawData);


 private :
        map<int, map<int,int> >* FEDmap;
	map<int, map<int,int> >* FEDorder;


};



#endif


