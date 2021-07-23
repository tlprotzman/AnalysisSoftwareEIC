
// ANCHOR debug output verbosity
int int_CS_verbosity = 2;

const int nParticlesPDG_CS = 7;
int int_CS_mcparticles_PDG[nParticlesPDG_CS] = {11 /*e*/,22 /*gamma*/,211  /*pi*/,  2212/*p*/,  2112/*n*/,  321/*K*/, 13/*mu*/};
TString str_CS_mcparticles[nParticlesPDG_CS] = {"electron", "photon", "cpion", "proton", "neutron", "ckaon", "muon"};

// ANCHOR create histograms globally
TH1F*  h_CS_clusters_E[_active_calo][_active_algo] = {{NULL}};
TH2F*  h_CS_clusters_M02_E[_active_calo][_active_algo] = {{NULL}};
TH2F*  h_CS_clusters_M02_part_E_truth[_active_calo][_active_algo][nParticlesPDG_CS] = {{{NULL}}};
TH2F*  h_CS_clusters_M20_E[_active_calo][_active_algo] = {{NULL}};
TH2F*  h_CS_clusters_M20_part_E_truth[_active_calo][_active_algo][nParticlesPDG_CS] = {{{NULL}}};
TH2F*  h_CS_clusters_NTower_E[_active_calo][_active_algo] = {{NULL}};
TH1D*  h_CS_clusters_NTowerMean_E[_active_calo][_active_algo] = {{NULL}};

TH2F*  h_clusterizer_clsspec_matched_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecMC_matched_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH1F*  h_clusterizer_clsspec_PDG[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH1F*  h_clusterizer_clsspec_matched_PDG[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]

TH2F*  h_clusterizer_1tower_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_1towerMC_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspec_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecMC_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspec_particle_E_eta[_active_calo][_active_algo][nParticlesPDG_CS]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecMC_particle_E_eta[_active_calo][_active_algo][nParticlesPDG_CS]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspec_matched_particle_E_eta[_active_calo][_active_algo][nParticlesPDG_CS]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecMC_matched_particle_E_eta[_active_calo][_active_algo][nParticlesPDG_CS]; // [calorimeter_enum][algorithm_enu

TH2F*  h_clusterizer_clsspecSE_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecSEMC_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecSE_matched_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecSEMC_matched_E_eta[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecSE_E_NCl[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecSEMC_E_NCl[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH1D*  h_clusterizer_NClMean_E[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH1D*  h_clusterizer_NClMean_MCE[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]

TH1F*  h_clusterizer_NClPerMCLabel[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]
TH1F*  h_clusterizer_ClSameMCLabel_dR[_active_calo][_active_algo]; // [calorimeter_enum][algorithm_enum]

TH2F*  h_clusterizer_clsspecSE_particle_E_eta[_active_calo][_active_algo][nParticlesPDG_CS]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecSEMC_particle_E_eta[_active_calo][_active_algo][nParticlesPDG_CS]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecSE_matched_particle_E_eta[_active_calo][_active_algo][nParticlesPDG_CS]; // [calorimeter_enum][algorithm_enum]
TH2F*  h_clusterizer_clsspecSEMC_matched_particle_E_eta[_active_calo][_active_algo][nParticlesPDG_CS]; // [calorimeter_enum][algorithm_enum]

int nclusters_CLSTD = 0;
float* clusters_CLSTD_E         = new float[_maxNclusters];
float* clusters_CLSTD_Eta       = new float[_maxNclusters];
float* clusters_CLSTD_Phi       = new float[_maxNclusters];
float* clusters_CLSTD_M02       = new float[_maxNclusters];
float* clusters_CLSTD_M20       = new float[_maxNclusters];
bool* clusters_CLSTD_isMatched  = new bool[_maxNclusters];
int* clusters_CLSTD_NTower      = new int[_maxNclusters];
int* clusters_CLSTD_trueID      = new int[_maxNclusters];
int* clusters_CLSTD_NtrueID     = new int[_maxNclusters];
float* clusters_CLSTD_X         = new float[_maxNclusters];
float* clusters_CLSTD_Y         = new float[_maxNclusters];
float* clusters_CLSTD_Z         = new float[_maxNclusters];

TH2F* h_clusterizer_IEtaIPhiMapEvt 	    = new TH2F("h_clusterizer_IEtaIPhiMapEvt", "",  57, -0.5, 56.5,  57, -0.5, 56.5);;
// TH2F* h_clusterizer_IEtaIPhiMapEvt 	    = new TH2F("h_clusterizer_IEtaIPhiMapEvt", "",  23, 13.5, 36.5,  23, 13.5, 36.5);;
TCanvas* cReso_clusterizer = new TCanvas("cReso_clusterizer","",0,0,1000,1000);

// ANCHOR main function to be called in event loop
void clusterstudies(){
  for(int icalo=0;icalo<_active_calo;icalo++){
    for(int ialgo=0;ialgo<_active_algo;ialgo++){

      // initialize histos if not yet done
      if(!h_CS_clusters_E[icalo][ialgo])h_CS_clusters_E[icalo][ialgo]= new TH1F(Form("h_CS_clusters_E_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP);
      if(!h_CS_clusters_M02_E[icalo][ialgo])h_CS_clusters_M02_E[icalo][ialgo]= new TH2F(Form("h_CS_clusters_M02_E_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "" , 100, 0, 2, nBinsP, binningP);
      if(!h_CS_clusters_M20_E[icalo][ialgo])h_CS_clusters_M20_E[icalo][ialgo]= new TH2F(Form("h_CS_clusters_M20_E_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "" , 100, 0, 2, nBinsP, binningP);
      if(!h_CS_clusters_NTower_E[icalo][ialgo])h_CS_clusters_NTower_E[icalo][ialgo]= new TH2F(Form("h_CS_clusters_NTower_E_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "" , nBinsP, binningP, 30, -0.5, 29.5);
      if(!h_clusterizer_clsspec_matched_E_eta[icalo][ialgo])h_clusterizer_clsspec_matched_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspec_matched_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
      if(!h_clusterizer_clsspecMC_matched_E_eta[icalo][ialgo])h_clusterizer_clsspecMC_matched_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspecMC_matched_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);

      if(!h_clusterizer_1tower_E_eta[icalo][ialgo])h_clusterizer_1tower_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_1tower_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
      if(!h_clusterizer_1towerMC_E_eta[icalo][ialgo])h_clusterizer_1towerMC_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_1towerMC_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);

      if(!h_clusterizer_clsspec_E_eta[icalo][ialgo])h_clusterizer_clsspec_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspec_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
      if(!h_clusterizer_clsspecMC_E_eta[icalo][ialgo])h_clusterizer_clsspecMC_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspecMC_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);

      if(!h_clusterizer_clsspecSE_E_eta[icalo][ialgo])h_clusterizer_clsspecSE_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspecSE_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
      if(!h_clusterizer_clsspecSEMC_E_eta[icalo][ialgo])h_clusterizer_clsspecSEMC_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspecSEMC_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
      if(!h_clusterizer_clsspecSE_matched_E_eta[icalo][ialgo])h_clusterizer_clsspecSE_matched_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspecSE_matched_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
      if(!h_clusterizer_clsspecSEMC_matched_E_eta[icalo][ialgo])h_clusterizer_clsspecSEMC_matched_E_eta[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspecSEMC_matched_E_eta_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, -4.0,4.0);

      if(!h_clusterizer_clsspecSE_E_NCl[icalo][ialgo])h_clusterizer_clsspecSE_E_NCl[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspecSE_E_NCl_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, 0.5, 80.5);
      if(!h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo])h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo] 	= new TH2F(Form("h_clusterizer_clsspecSEMC_E_NCl_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", nBinsP, binningP, 80, 0.5, 80.5);

      if(!h_clusterizer_clsspec_PDG[icalo][ialgo])h_clusterizer_clsspec_PDG[icalo][ialgo] 	= new TH1F(Form("h_clusterizer_clsspec_PDG_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", 2500,0,2500);
      if(!h_clusterizer_clsspec_matched_PDG[icalo][ialgo])h_clusterizer_clsspec_matched_PDG[icalo][ialgo] 	= new TH1F(Form("h_clusterizer_clsspec_matched_PDG_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", 2500,0,2500);

      if(!h_clusterizer_NClPerMCLabel[icalo][ialgo])h_clusterizer_NClPerMCLabel[icalo][ialgo] 	= new TH1F(Form("h_clusterizer_NClPerMCLabel_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "", 10,-0.5,9.5);
      if(!h_clusterizer_ClSameMCLabel_dR[icalo][ialgo])h_clusterizer_ClSameMCLabel_dR[icalo][ialgo] 	= new TH1F(Form("h_clusterizer_ClSameMCLabel_dR_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()), "",600,0,600);

      for (int iPDG = 0; iPDG < nParticlesPDG_CS; iPDG++){
        if(!h_CS_clusters_M02_part_E_truth[icalo][ialgo][iPDG])h_CS_clusters_M02_part_E_truth[icalo][ialgo][iPDG]= new TH2F(Form("h_CS_clusters_M02_part_E_truth_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "" , 100, 0, 2, nBinsP, binningP);
        if(!h_CS_clusters_M20_part_E_truth[icalo][ialgo][iPDG])h_CS_clusters_M20_part_E_truth[icalo][ialgo][iPDG]= new TH2F(Form("h_CS_clusters_M20_part_E_truth_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "" , 100, 0, 2, nBinsP, binningP);
        if(!h_clusterizer_clsspec_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspec_particle_E_eta[icalo][ialgo][iPDG] 	= new TH2F(Form("h_clusterizer_clsspec_particle_E_eta_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
        if(!h_clusterizer_clsspecMC_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspecMC_particle_E_eta[icalo][ialgo][iPDG] 	= new TH2F(Form("h_clusterizer_clsspecMC_particle_E_eta_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
        if(!h_clusterizer_clsspecSE_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspecSE_particle_E_eta[icalo][ialgo][iPDG] 	= new TH2F(Form("h_clusterizer_clsspecSE_particle_E_eta_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
        if(!h_clusterizer_clsspecSEMC_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspecSEMC_particle_E_eta[icalo][ialgo][iPDG] 	= new TH2F(Form("h_clusterizer_clsspecSEMC_particle_E_eta_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
        if(!h_clusterizer_clsspec_matched_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspec_matched_particle_E_eta[icalo][ialgo][iPDG] 	= new TH2F(Form("h_clusterizer_clsspec_matched_particle_E_eta_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
        if(!h_clusterizer_clsspecMC_matched_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspecMC_matched_particle_E_eta[icalo][ialgo][iPDG] 	= new TH2F(Form("h_clusterizer_clsspecMC_matched_particle_E_eta_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
        if(!h_clusterizer_clsspecSE_matched_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspecSE_matched_particle_E_eta[icalo][ialgo][iPDG] 	= new TH2F(Form("h_clusterizer_clsspecSE_matched_particle_E_eta_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
        if(!h_clusterizer_clsspecSEMC_matched_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspecSEMC_matched_particle_E_eta[icalo][ialgo][iPDG] 	= new TH2F(Form("h_clusterizer_clsspecSEMC_matched_particle_E_eta_%s_%s_%s",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data(),str_CS_mcparticles[iPDG].Data()), "", nBinsP, binningP, 80, -4.0,4.0);
      }

      if(!loadClusterizerInput(
        ialgo,
        icalo,
        nclusters_CLSTD,
        clusters_CLSTD_E,
        clusters_CLSTD_Eta,
        clusters_CLSTD_Phi,
        clusters_CLSTD_M02,
        clusters_CLSTD_M20,
        clusters_CLSTD_isMatched,
        clusters_CLSTD_NTower,
        clusters_CLSTD_trueID,
        clusters_CLSTD_NtrueID,
        clusters_CLSTD_X,
        clusters_CLSTD_Y,
        clusters_CLSTD_Z
      )) continue;

      std::vector<occuranceStrct> uniqueIDs;
      std::vector<float> usedIDs;
      int foundmultclus = 0;
      int foundmultclusM02 = 0;
      for(Int_t iclus=0; iclus<nclusters_CLSTD; iclus++){
        Bool_t particleFilled   = kFALSE;
        Double_t highestEnergy  = clusters_CLSTD_E[iclus];
        Bool_t isHighest        = kFALSE;
        Int_t nClPerParticle    = 1;
        for (Int_t bclus = iclus+1; bclus < nclusters_CLSTD; bclus++ ){
            if (clusters_CLSTD_trueID[iclus] != clusters_CLSTD_trueID[bclus]) continue;
            if (clusters_CLSTD_E[bclus] > clusters_CLSTD_E[iclus])
              highestEnergy = clusters_CLSTD_E[iclus];
            nClPerParticle++;
        }
        if (clusters_CLSTD_E[iclus] == highestEnergy)
          isHighest = kTRUE;
        for (int id = 0; id < uniqueIDs.size() && !particleFilled ; id++){
          if ( uniqueIDs.at(id).particle_ID == (int)(clusters_CLSTD_trueID[iclus]) )
            particleFilled = kTRUE;
        }

        usedIDs.push_back(iclus);
        int icluswithsamelabel = 1;
        int icluswithsamelabelM02 = 0;
        if(clusters_CLSTD_NTower[iclus]>1)icluswithsamelabelM02++;
        for(Int_t icluslbl=0; icluslbl<nclusters_CLSTD; icluslbl++){
          if((int)(clusters_CLSTD_trueID[iclus])==(int)(clusters_CLSTD_trueID[icluslbl])){

            if ( !(std::find(usedIDs.begin(), usedIDs.end(), icluslbl) != usedIDs.end()) ){
              usedIDs.push_back(icluslbl);
              icluswithsamelabel++;
              h_clusterizer_ClSameMCLabel_dR[icalo][ialgo]->Fill(TMath::Sqrt(TMath::Power(clusters_CLSTD_X[iclus]-clusters_CLSTD_X[icluslbl],2)+TMath::Power(clusters_CLSTD_Y[iclus]-clusters_CLSTD_Y[icluslbl],2)));
              if(clusters_CLSTD_NTower[icluslbl]>1)icluswithsamelabelM02++;
            }
          }
        }
        if(icalo==kFHCAL){
          if(icluswithsamelabel>1)foundmultclus = icluswithsamelabel;
          foundmultclusM02 = icluswithsamelabelM02;
        }
        h_clusterizer_NClPerMCLabel[icalo][ialgo]->Fill(icluswithsamelabel);


        h_CS_clusters_NTower_E[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus],clusters_CLSTD_NTower[iclus]);
        h_CS_clusters_E[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus]);
        h_CS_clusters_M02_E[icalo][ialgo]->Fill(clusters_CLSTD_M02[iclus],clusters_CLSTD_E[iclus]);
        h_CS_clusters_M20_E[icalo][ialgo]->Fill(clusters_CLSTD_M20[iclus],clusters_CLSTD_E[iclus]);

        for (int iPDG = 0; iPDG < nParticlesPDG_CS; iPDG++){
          if(abs(_mcpart_PDG[clusters_CLSTD_trueID[iclus]]) == abs(int_CS_mcparticles_PDG[iPDG])){
            h_CS_clusters_M02_part_E_truth[icalo][ialgo][iPDG]->Fill(clusters_CLSTD_M02[iclus],clusters_CLSTD_E[iclus]);
            h_CS_clusters_M20_part_E_truth[icalo][ialgo][iPDG]->Fill(clusters_CLSTD_M20[iclus],clusters_CLSTD_E[iclus]);
          }
        }
        if (clusters_CLSTD_NTower[iclus] < 2){
          h_clusterizer_1tower_E_eta[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
          h_clusterizer_1towerMC_E_eta[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);
          if (!particleFilled && isHighest){
            h_clusterizer_clsspecSE_E_eta[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
            h_clusterizer_clsspecSEMC_E_eta[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);
            h_clusterizer_clsspecSE_E_NCl[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], nClPerParticle);
            h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], nClPerParticle);          
            if (clusters_CLSTD_isMatched[iclus]){
              h_clusterizer_clsspecSE_matched_E_eta[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
              h_clusterizer_clsspecSEMC_matched_E_eta[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);          
            }
            for(int iPDG=0;iPDG<nParticlesPDG_CS;iPDG++){
              if(int_CS_mcparticles_PDG[iPDG]==abs(_mcpart_PDG[clusters_CLSTD_trueID[iclus]])){
                h_clusterizer_clsspecSE_particle_E_eta[icalo][ialgo][iPDG]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
                h_clusterizer_clsspecSEMC_particle_E_eta[icalo][ialgo][iPDG]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);
                if (clusters_CLSTD_isMatched[iclus]){
                  h_clusterizer_clsspecSE_matched_particle_E_eta[icalo][ialgo][iPDG]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
                  h_clusterizer_clsspecSEMC_matched_particle_E_eta[icalo][ialgo][iPDG]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);                  
                }
              }
            }
          }
        } else {
          // fill inputs for efficiency
          h_clusterizer_clsspec_E_eta[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
          h_clusterizer_clsspecMC_E_eta[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);
          if (clusters_CLSTD_isMatched[iclus]){
            h_clusterizer_clsspec_matched_E_eta[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
            h_clusterizer_clsspecMC_matched_E_eta[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);
          }
          if (!particleFilled && isHighest){
            h_clusterizer_clsspecSE_E_eta[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
            h_clusterizer_clsspecSEMC_E_eta[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);          
            h_clusterizer_clsspecSE_E_NCl[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], nClPerParticle);
            h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], nClPerParticle);          
            if (clusters_CLSTD_isMatched[iclus]){
              h_clusterizer_clsspecSE_matched_E_eta[icalo][ialgo]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
              h_clusterizer_clsspecSEMC_matched_E_eta[icalo][ialgo]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);          
            }
          }
          
          for(int iPDG=0;iPDG<nParticlesPDG_CS;iPDG++){
            if(int_CS_mcparticles_PDG[iPDG]==abs(_mcpart_PDG[clusters_CLSTD_trueID[iclus]])){
              h_clusterizer_clsspec_particle_E_eta[icalo][ialgo][iPDG]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
              h_clusterizer_clsspecMC_particle_E_eta[icalo][ialgo][iPDG]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);
              if (clusters_CLSTD_isMatched[iclus]){
                h_clusterizer_clsspec_matched_particle_E_eta[icalo][ialgo][iPDG]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
                h_clusterizer_clsspecMC_matched_particle_E_eta[icalo][ialgo][iPDG]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);
              }
              if (!particleFilled && isHighest){
                h_clusterizer_clsspecSE_particle_E_eta[icalo][ialgo][iPDG]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
                h_clusterizer_clsspecSEMC_particle_E_eta[icalo][ialgo][iPDG]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);
                if (clusters_CLSTD_isMatched[iclus]){
                  h_clusterizer_clsspecSE_matched_particle_E_eta[icalo][ialgo][iPDG]->Fill(clusters_CLSTD_E[iclus], clusters_CLSTD_Eta[iclus]);
                  h_clusterizer_clsspecSEMC_matched_particle_E_eta[icalo][ialgo][iPDG]->Fill(_mcpart_E[clusters_CLSTD_trueID[iclus]], _mcpart_Eta[clusters_CLSTD_trueID[iclus]]);                  
                }
              }
            }
          }
          h_clusterizer_clsspec_PDG[icalo][ialgo]->Fill(abs(_mcpart_PDG[clusters_CLSTD_trueID[iclus]]));
          if(clusters_CLSTD_isMatched[iclus]) h_clusterizer_clsspec_matched_PDG[icalo][ialgo]->Fill(abs(_mcpart_PDG[clusters_CLSTD_trueID[iclus]]));
        }
        if (!particleFilled && isHighest){
          occuranceStrct tempstructCl;
          tempstructCl.particle_ID = clusters_CLSTD_trueID[iclus];
          tempstructCl.highest_E = highestEnergy;
          tempstructCl.nClusters = nClPerParticle;
          uniqueIDs.push_back(tempstructCl);
//           if (tempstructCl.nClusters > 1) cout << "particle: " << tempstructCl.particle_ID << " has multiple clusters (" << tempstructCl.nClusters << ") for " << str_calorimeter[icalo].Data() << " " << str_clusterizer[ialgo].Data() << endl;
        }
      }
      if(0 && foundmultclus && ialgo==kMA && icalo==kFHCAL){
        float sumtowerE = 0;
        h_clusterizer_IEtaIPhiMapEvt->Reset("ICESM");
        for(int itow=0; itow<_nTowers_FHCAL; itow++){
          if(_tower_FHCAL_E[itow]>(0.05)){
            h_clusterizer_IEtaIPhiMapEvt->Fill(_tower_FHCAL_iEta[itow], _tower_FHCAL_iPhi[itow],_tower_FHCAL_E[itow]*2);
            sumtowerE+=_tower_FHCAL_E[itow];
          }
        }
        cReso_clusterizer->cd();
        gStyle->SetOptStat(0);
        gStyle->SetPaintTextFormat("1.3f");
        cReso_clusterizer->SetLogz();
        h_clusterizer_IEtaIPhiMapEvt->Draw("colz");
        h_clusterizer_IEtaIPhiMapEvt->SetMarkerSize(0.25);
        float texty = 1;
        TLatex *latexDummy;
        for(Int_t iclus=0; iclus<nclusters_CLSTD; iclus++){
          latexDummy                          = new TLatex(10 ,texty,Form("Twrs: %d, E: %2.3f PDG: %d",clusters_CLSTD_NTower[iclus],clusters_CLSTD_E[iclus],_mcpart_PDG[clusters_CLSTD_trueID[iclus]]));
          latexDummy->SetTextFont(42);
          latexDummy->SetTextSize(35./1200);
          latexDummy->SetLineWidth(4);
          latexDummy->SetTextAlign(11);
          latexDummy->SetTextColor(kBlack);
          latexDummy->Draw();
          texty+=2;
        }
        h_clusterizer_IEtaIPhiMapEvt->Draw("same,text");
        cReso_clusterizer->SaveAs(Form("%s/etaphi/%d_%d_%2.6f.pdf",outputDir.Data(),foundmultclus,foundmultclusM02,sumtowerE));
      }
      uniqueIDs.clear();
      usedIDs.clear();
    }
  }
}

// ANCHOR save function after event loop
void clusterstudiesSave(){
  // gSystem->Exec("mkdir -p treeProcessing/clusterstudies");
  // define output file
  for(int icalo=0;icalo<_active_calo;icalo++){
    for(int ialgo=0;ialgo<_active_algo;ialgo++){

      h_CS_clusters_NTowerMean_E[icalo][ialgo]  = new TH1D(Form("h_CS_NTowerMean_%s_%s_E",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()),"",nP, partP);
      h_clusterizer_NClMean_E[icalo][ialgo]     = new TH1D(Form("h_CS_NClMean_%s_%s_E",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()),"",nP, partP);
      h_clusterizer_NClMean_MCE[icalo][ialgo]   = new TH1D(Form("h_CS_NClMean_%s_%s_MCE",str_calorimeter[icalo].Data(),str_clusterizer[ialgo].Data()),"",nP, partP);

      if(h_CS_clusters_NTower_E[icalo][ialgo]){
        // make projections for JES and JER
        for (Int_t i=1; i < nP+1; i++){
          TH1D* projectionYdummy = (TH1D*)h_CS_clusters_NTower_E[icalo][ialgo]->ProjectionY(Form("projectionYdummy%d_%d_%d",icalo, ialgo,i), h_CS_clusters_NTower_E[icalo][ialgo]->GetXaxis()->FindBin(partP[i-1]+0.001), h_CS_clusters_NTower_E[icalo][ialgo]->GetXaxis()->FindBin(partP[i]+0.001),"e");
          // projectionYdummy->GetXaxis()->SetRangeUser(-0.6,0);
          h_CS_clusters_NTowerMean_E[icalo][ialgo]->SetBinContent(i,projectionYdummy->GetMean());
          h_CS_clusters_NTowerMean_E[icalo][ialgo]->SetBinError(i,projectionYdummy->GetStdDev());
        }
      }
      if(h_clusterizer_clsspecSE_E_NCl[icalo][ialgo]){
        // make projections for JES and JER
        for (Int_t i=1; i < nP+1; i++){
          TH1D* projectionYdummy = (TH1D*)h_clusterizer_clsspecSE_E_NCl[icalo][ialgo]->ProjectionY(Form("projectionYdummy%d_%d_%d",icalo, ialgo,i), h_clusterizer_clsspecSE_E_NCl[icalo][ialgo]->GetXaxis()->FindBin(partP[i-1]+0.001), h_clusterizer_clsspecSE_E_NCl[icalo][ialgo]->GetXaxis()->FindBin(partP[i]+0.001),"e");
          // projectionYdummy->GetXaxis()->SetRangeUser(-0.6,0);
          h_clusterizer_NClMean_E[icalo][ialgo]->SetBinContent(i,projectionYdummy->GetMean());
          h_clusterizer_NClMean_E[icalo][ialgo]->SetBinError(i,projectionYdummy->GetStdDev());
        }
      }
      if(h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo]){
        // make projections for JES and JER
        for (Int_t i=1; i < nP+1; i++){
          TH1D* projectionYdummy = (TH1D*)h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo]->ProjectionY(Form("projectionYdummy%d_%d_%d",icalo, ialgo,i), h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo]->GetXaxis()->FindBin(partP[i-1]+0.001), h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo]->GetXaxis()->FindBin(partP[i]+0.001),"e");
          // projectionYdummy->GetXaxis()->SetRangeUser(-0.6,0);
          h_clusterizer_NClMean_MCE[icalo][ialgo]->SetBinContent(i,projectionYdummy->GetMean());
          h_clusterizer_NClMean_MCE[icalo][ialgo]->SetBinError(i,projectionYdummy->GetStdDev());
        }
      }
    }
  }

  
  TFile* fileOutput = new TFile(Form("%s/output_CS.root",outputDir.Data()),"RECREATE");

  // write histograms
  for(int icalo=0;icalo<_active_calo;icalo++){
    fileOutput->mkdir(Form("%s",str_calorimeter[icalo].Data()));
    fileOutput->cd(Form("%s",str_calorimeter[icalo].Data()));
    for(int ialgo=0;ialgo<_active_algo;ialgo++){
      if(h_CS_clusters_NTower_E[icalo][ialgo]) h_CS_clusters_NTower_E[icalo][ialgo]->Write();
      if(h_CS_clusters_NTowerMean_E[icalo][ialgo]) h_CS_clusters_NTowerMean_E[icalo][ialgo]->Write();
      if(h_CS_clusters_E[icalo][ialgo]) h_CS_clusters_E[icalo][ialgo]->Write();
      if(h_CS_clusters_M02_E[icalo][ialgo]) h_CS_clusters_M02_E[icalo][ialgo]->Write();
      if(h_CS_clusters_M20_E[icalo][ialgo]) h_CS_clusters_M20_E[icalo][ialgo]->Write();
      if(h_clusterizer_clsspec_matched_E_eta[icalo][ialgo]) h_clusterizer_clsspec_matched_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_clsspecMC_matched_E_eta[icalo][ialgo]) h_clusterizer_clsspecMC_matched_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_clsspec_PDG[icalo][ialgo]) h_clusterizer_clsspec_PDG[icalo][ialgo]->Write();
      if(h_clusterizer_clsspec_matched_PDG[icalo][ialgo]) h_clusterizer_clsspec_matched_PDG[icalo][ialgo]->Write();
      if(h_clusterizer_1tower_E_eta[icalo][ialgo]) h_clusterizer_1tower_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_1towerMC_E_eta[icalo][ialgo]) h_clusterizer_1towerMC_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_clsspec_E_eta[icalo][ialgo]) h_clusterizer_clsspec_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_clsspecMC_E_eta[icalo][ialgo]) h_clusterizer_clsspecMC_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_clsspecSE_E_eta[icalo][ialgo]) h_clusterizer_clsspecSE_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_clsspecSEMC_E_eta[icalo][ialgo]) h_clusterizer_clsspecSEMC_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_clsspecSE_E_NCl[icalo][ialgo]) h_clusterizer_clsspecSE_E_NCl[icalo][ialgo]->Write();
      if(h_clusterizer_NClMean_E[icalo][ialgo]) h_clusterizer_NClMean_E[icalo][ialgo]->Write();
      if(h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo]) h_clusterizer_clsspecSEMC_E_NCl[icalo][ialgo]->Write();
      if(h_clusterizer_NClMean_MCE[icalo][ialgo]) h_clusterizer_NClMean_MCE[icalo][ialgo]->Write();
      if(h_clusterizer_clsspecSE_matched_E_eta[icalo][ialgo]) h_clusterizer_clsspecSE_matched_E_eta[icalo][ialgo]->Write();
      if(h_clusterizer_clsspecSEMC_matched_E_eta[icalo][ialgo]) h_clusterizer_clsspecSEMC_matched_E_eta[icalo][ialgo]->Write();

      if(h_clusterizer_NClPerMCLabel[icalo][ialgo]) h_clusterizer_NClPerMCLabel[icalo][ialgo]->Write();
      if(h_clusterizer_ClSameMCLabel_dR[icalo][ialgo]) h_clusterizer_ClSameMCLabel_dR[icalo][ialgo]->Write();
    
      for (int iPDG = 0; iPDG < nParticlesPDG_CS; iPDG++){
        if(h_CS_clusters_M02_part_E_truth[icalo][ialgo][iPDG]) h_CS_clusters_M02_part_E_truth[icalo][ialgo][iPDG]->Write();
        if(h_CS_clusters_M20_part_E_truth[icalo][ialgo][iPDG]) h_CS_clusters_M20_part_E_truth[icalo][ialgo][iPDG]->Write();
        if(h_clusterizer_clsspec_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspec_particle_E_eta[icalo][ialgo][iPDG]->Write();
        if(h_clusterizer_clsspecMC_particle_E_eta[icalo][ialgo][iPDG]) h_clusterizer_clsspecMC_particle_E_eta[icalo][ialgo][iPDG]->Write();
        if(h_clusterizer_clsspecSE_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspecSE_particle_E_eta[icalo][ialgo][iPDG]->Write();
        if(h_clusterizer_clsspecSEMC_particle_E_eta[icalo][ialgo][iPDG]) h_clusterizer_clsspecSEMC_particle_E_eta[icalo][ialgo][iPDG]->Write();
        if(h_clusterizer_clsspec_matched_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspec_matched_particle_E_eta[icalo][ialgo][iPDG]->Write();
        if(h_clusterizer_clsspecMC_matched_particle_E_eta[icalo][ialgo][iPDG]) h_clusterizer_clsspecMC_matched_particle_E_eta[icalo][ialgo][iPDG]->Write();
        if(h_clusterizer_clsspecSE_matched_particle_E_eta[icalo][ialgo][iPDG])h_clusterizer_clsspecSE_matched_particle_E_eta[icalo][ialgo][iPDG]->Write();
        if(h_clusterizer_clsspecSEMC_matched_particle_E_eta[icalo][ialgo][iPDG]) h_clusterizer_clsspecSEMC_matched_particle_E_eta[icalo][ialgo][iPDG]->Write();
      }
    }
  }
  // write output file
  fileOutput->Write();
  fileOutput->Close();
}
