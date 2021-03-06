//===========================================================
//                 MACRO TO MAKE NTUPLE PLOTS
//===========================================================

void make_NTuple_plots_NHits(TString file){
  

  // Get file and TTree (TTree works only for files of the type 'SupernovaAna.root'
  // Otherwise the directory and TTree must be changed accordingly
  TFile *file1 = new TFile(file);
  //TFile *file1 = new TFile("SupernovaAna_radiological1_hist.root");
  gDirectory->cd("supernovaana");
  TTree *tree1 = (TTree*)gDirectory->Get("SupernovaAna");
  //tree1->SetMarkerStyle();

  /*

  TCanvas *cNHitsVRadius = new TCanvas("cSummedADCV","SummedADCV");
  cSummedADCV->Divide(2,1);
  cSummedADCV->cd(1);
  TH2F *hSummedADCVNuEnergy = new TH2F("hSummedADCVNuEnergy","Summed ADC against neutrino energy ;Neutrino energy;Summed ADC",81,-0.001,0.081,100,0,160e3);
  tree1->Draw("SummedADC:NuEnergyTruths >> hSummedADCVNuEnergy");
  hSummedADCVNuEnergy->Draw("colz");

  */

  // Create cuts
  TCut NuEnergyGT0 = "NuEnergyTruths >= 0.0";
  TCut NuEnrgyLT10 = "NuEnergyTruths < 10.0";
  TCut NHitsLT2 = "NHits <=2";
  TCut NHitsLT20 = "NHits <=20";
  TCut NHitsGT20 = "NHits >=20";
  TCut HitXValid = "HitX > - 1000";
  TCut Particle1 = "ParticleNo == 1";

  // Create Fits
  TF1 *Poisson1 = new TF1("Poisson1","[0]*TMath::Poisson(x,[1])",0,50);
  TF1 *Poisson2 = new TF1("Poisson2","[0]*TMath::Power(([1]/[2]),(x/[2]))*(TMath::Exp(-([1]/[2])))/TMath::Gamma((x/[2])+1)",0.0,0.1); //last two are xmin and xmax
  

  //tree1->GetListOfBranches->Print();
  // Create histograms on seperate canvases 

  int NHits;
  int NCollectionHits;
  double HitX[5000];
  double HitY[5000];
  double HitZ[5000];
  double HitTrueE[5000];
  tree1->SetBranchAddress("NHits",&NHits);
  tree1->SetBranchAddress("NCollectionHits",&NCollectionHits);
  tree1->SetBranchAddress("HitX",&HitX);
  tree1->SetBranchAddress("HitY",&HitY);
  tree1->SetBranchAddress("HitZ",&HitZ);
  tree1->SetBranchAddress("HitTrueE",&HitTrueE);  
  
  TCanvas *cPlot1 = new TCanvas("cPlot1","Plot1");
  cPlot1->cd();
  TH1F *hPlot1 = new TH1F("hPlot1","Plot number one;x-hits;Count",10000,-400,400);
  hPlot1->SetXTitle("x-position [cm]");
  hPlot1->SetYTitle("Frequency");  
  //hPlot1->GetXaxis()->SetTitleSize(.5);
  tree1->Draw("HitX >> hPlot1",HitXValid); 
  
  
  /*

  TCanvas *cNMCTruths = new TCanvas("cNMCTruths","NMCTruths");
  cNMCTruths->cd();
  TH1F *hNMCTruths = new TH1F("hNMCTruths","Number of MC truths per events;N MC truths;Count",100,-0.5,100.5);
  tree1->Draw("NMCTruths >> hNMCTruths");
  hNMCTruths->Draw();
  Poisson1->SetParameters(2,20);
  hNMCTruths->Fit("Poisson1");

  */

  // We define the quantities to be used in the profile here as as single valued floats/doubles/ints
  // so that we can obtain their real values for each branch entry which is done in the following loop  
  // double HitTrueE;

  // Create pointers to the above variables which can be called upon when we assign values to them
  // The branches are being read from the .root file and can then be accessed through these local variables 

  //tree1->SetBranchAddress("HitTrueE",&HitTrueE);
 

  TCanvas *cPlot2 = new TCanvas("cPlot2","Average energy per bin vs x-position");
  cPlot2->cd();

  //TH2F *hPlot2 = new TH2F("hPlot2","Average electron energy per x-bin",1000,-400.8,400.8,1000,-0.06,6.06);

  // Define the profile
  TProfile *myProfile = new TProfile("myProfile","Average electron energy per x-bin",50,-400.8,400.8,0.0,6.0);;
  myProfile->SetXTitle("x-position [cm]");
  myProfile->SetYTitle("Average energy per x-bin [MeV]");  
  // Loop over each entry in the branches for HitX and HitTrueE 
  for(int i=0; i < tree1->GetEntries(); i++){ // need really two counting indicies
    // tree1->GetBranch("HitX")->GetEntry(i);
    std::cout << "number of entries:" << tree1->GetEntries() << endl;
    tree1->GetEntry(i);
    for(int j=0; j< NCollectionHits; j++)
      {
	//std::cout << j << "th x-position:" << HitX[j] << endl;
	//std::cout << j << "th energy:" << HitTrueE[j] << endl;
	
	//hPlot2->Fill(HitX[j], HitTrueE[j]);
	myProfile->Fill(HitX[j], HitTrueE[j]);
      }
 
    //std::cout << "No. of hits:" << NHits << endl;
    //myProfile->Fill(HitX,HitTrueE);
  }
  myProfile->Draw("colz");

  // Plot of hits for one event to show traces
  //TCanvas *cPlot3 = new TCanvas("cPlot3","plot");
  //cPlot3->cd();

  TH2F *hPlot3 = new TH2F("hPlot3","x-z cross-section weighted by energy",100,-400,400,100,0,1200);
  TH3F *hPlot4 = new TH3F("hPlot4","Position",100,-400,400,100,-800,800,100,0,1200);
  TGraph2D *gPlot5 = new TGraph2D();

  for(int i=0; i < 1; i++){ 
    std::cout << "number of entries:" << tree1->GetEntries() << endl;
    tree1->GetEntry(i);
    for(int j=0; j< NCollectionHits; j++)
      {
	std::cout << j << "th x-position:" << HitX[j] << endl;
	std::cout << j << "th y-position:" << HitY[j] << endl;
	hPlot3->Fill(HitX[j], HitZ[j],HitTrueE[j]);
	hPlot4->Fill(HitX[j], HitY[j],HitZ[j]);
	gPlot5->SetPoint(j,HitX[j], HitY[j],HitZ[j]);
	//myProfile->Fill(HitX[j], HitTrueE[j]);
      }
    }
	
  TCanvas *cPlot3 = new TCanvas("cPlot3","X-Z cross-section");
  cPlot3->cd();
  hPlot3->SetXTitle("x [cm]");
  hPlot3->SetYTitle("z [cm]");  
  hPlot3->Draw("colz");

  /*
  TCanvas *cPlot4 = new TCanvas("cPlot4","3D histogram");
  cPlot4->cd();
  hPlot4->Draw(Particle1);

  TCanvas *cPlot5 = new TCanvas("cPlot5","3D graph");
  cPlot5->cd();
  gStyle->SetPalette(1);
  gPlot5->Draw("p");


  //fChain->GetTree()->GetEntry(entry);
  //  TCanvas *cPlot2 = new TCanvas("cPlot2","Average energy per bin vs x-position");
  //cPlot2->cd();
  //TH2F *hPlot2 = new TH2F("hPlot2","Avg",100,0,100,16,-400,400);
  //TProfile *hPlot2 = new TProfile("hPlot2","Title",16,-400,400,0,1000);
  //TProfile *HitTrueE = hPlot2->ProfileY("HitTrueE",0,1000);
  //hPlot2->Fill(HitX,HitTrueE);
  //hPlot2->Draw("HitX:HitTrueE >> hPlot2");
  //hPlot2->Draw();  
  */  
  /*

  TCanvas *cPDGCodeTruths = new TCanvas("cPDGCodeTruths","PDGCodeTruths");
  cPDGCodeTruths->Divide(2,1);
  cPDGCodeTruths->cd(1);
  TH1F *hNuPDGCodeTruths = new TH1F("hNuPDGCodeTruths","Number of neutrino MC events of specific PDG code;PDG code;Count",37,-18.5,18.5);
  tree1->Draw("NuPDGCodeTruths >> hNuPDGCodeTruths",NuEnergyGT0);
  hNuPDGCodeTruths->Draw();
  cPDGCodeTruths->cd(2);
  TH1F *hLeptonPDGCodeTruths = new TH1F("hLeptonPDGCodeTruths","Number of lepton MC events of specific PDG code;PDG code;Count",37,-18.5,18.5);
  tree1->Draw("LeptonPDGCodeTruths >> hLeptonPDGCodeTruths",NuEnergyGT0);
  hLeptonPDGCodeTruths->Draw();
  
  TCanvas *cEnergyTruths = new TCanvas("cEnergyTruths","EnergyTruths");
  cEnergyTruths->Divide(2,1);
  cEnergyTruths->cd(1);
  TH1F *hNuEnergyTruths = new TH1F("hNuEnergyTruths","Number of MC events of specific neutrino Energy;Nuetrino Energy [GeV];Count",81,-0.001,0.081);
  tree1->Draw("NuEnergyTruths >> hNuEnergyTruths",NuEnergyGT0);
  hNuEnergyTruths->Draw();
  cEnergyTruths->cd(2);
  TH1F *hLeptonEnergyTruths = new TH1F("hLeptonEnergyTruths","Number of MC events of specific lepton Energy;Lepton Energy [GeV];Count",81,-0.001,0.081);
  tree1->Draw("LeptonEnergyTruths >> hLeptonEnergyTruths",NuEnergyGT0);
  hLeptonEnergyTruths->Draw();

  TCanvas *cThetaTruths = new TCanvas("cThetaTruths","ThetaTruths");
  cThetaTruths->cd();
  TH1F *hThetaTruths = new TH1F("hThetaTruths","Number of MC events at angle #theta;#theta [rad];Count",100,-0.001,0.001);
  tree1->Draw("ThetaTruths >> hThetaTruths",NuEnergyGT0);
  hThetaTruths->Draw();

  TCanvas *cNMCTruthsV = new TCanvas("cNMCTruthsV","NMCTruthsV");
  cNMCTruthsV->Divide(2,1);
  cNMCTruthsV->cd(1);
  TH2F *hNMCTruthsVNHits = new TH2F("hNMCTruthsVNHits","Number of MC truths against number of hits ;N Hits;N MC Truths",101,-0.7,700.7,26,-0.5,25.5);
  tree1->Draw("NMCTruths:NHits >> hNMCTruthsVNHits");
  hNMCTruthsVNHits->Draw("colz");
  cNMCTruthsV->cd(2);
  TH2F *hNMCTruthsVSummedADC = new TH2F("hNMCTruthsVSummedADC","Number of MC truths against summed ADC ;Summed ADC;N MC Truths",100,0,160e3,26,-0.5,25.5);
  tree1->Draw("NMCTruths:SummedADC >> hNMCTruthsVSummedADC");
  hNMCTruthsVSummedADC->Draw("colz");

  TCanvas *cSummedADCV = new TCanvas("cSummedADCV","SummedADCV");
  cSummedADCV->Divide(2,1);
  cSummedADCV->cd(1);
  TH2F *hSummedADCVNuEnergy = new TH2F("hSummedADCVNuEnergy","Summed ADC against neutrino energy ;Neutrino energy;Summed ADC",81,-0.001,0.081,100,0,160e3);
  tree1->Draw("SummedADC:NuEnergyTruths >> hSummedADCVNuEnergy");
  hSummedADCVNuEnergy->Draw("colz");
  cSummedADCV->cd(2);
  TH2F *hSummedADCVLeptonEnergy = new TH2F("hSummedADCVLeptonEnergy","Summed ADC against lepton energy ;Lepton energy;Summed ADC",81,-0.001,0.081,100,0,160e3);
  tree1->Draw("SummedADC:LeptonEnergyTruths >> hSummedADCVLeptonEnergy");
  hSummedADCVLeptonEnergy->Draw("colz");

  // tTruths probably does not give the time over which the neutrinos arrive in the detector
  // but rather the time over which the leptons drift through it
  TCanvas *cNMCTruthsVTime = new TCanvas("cNMCTruthsVTime","NMCTruthsVTime");
  TH2F *hNMCTruthsVTime = new TH2F("hNMCTruthsVTime","Number of MC truths against time ;Time;N MC Truths",101,-0.7,700.7,26,-0.5,25.5);
  tree1->Draw("NMCTruths:tTruths >> hNMCTruthsVTime");
  hNMCTruthsVTime->Draw("colz");
 
 
  */
 

  /*
  TCanvas *cYZVertex = new TCanvas("cYZVertex","YZVertex");
  cYZVertex->Divide(2,2);
  cYZVertex->cd(1);
  TH2F *hYZVertex1 = new TH2F("hYZVertex1","Number of particles in y-z plane;z;y",100,-100,600,100,-700,700);
  tree1->Draw("yTruths:zTruths >> hYZVertex1");
  hYZVertex1->Draw("colz");
  cYZVertex->cd(2);
  TH2F *hYZVertex2 = new TH2F("hYZVertex2","Number of particles in y-z plane with less than two hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("yTruths:zTruths >> hYZVertex2",NHitsLT2);
  hYZVertex2->Draw("colz");
  cYZVertex->cd(3);
  TH2F *hYZVertex3 = new TH2F("hYZVertex3","Number of particles in y-z plane with less than twentry hitsMO;z;y",100,-100,600,100,-700,700);
  tree1->Draw("yTruths:zTruths >> hYZVertex3",NHitsLT20);
  hYZVertex3->Draw("colz");
  cYZVertex->cd(4);
  TH2F *hYZVertex4 = new TH2F("hYZVertex4","Number of particles in y-z plane with greater than twenty hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("yTruths:zTruths >> hYZVertex4",NHitsGT20);
  hYZVertex4->Draw("colz");


  TH2F *hXZVertex = new TH2F("hXZVertex","Number of particles in x-z plane;z;x",100,-100,600,100,-700,700);
  TCanvas *cXZVertex = new TCanvas("cXZVertex","XZVertex");
  cXZVertex->cd();
  tree1->Draw("xTruths:zTruths >> hXZVertex",NHitsLT2);
  hXZVertex->Draw("colz");
  */
  
}
