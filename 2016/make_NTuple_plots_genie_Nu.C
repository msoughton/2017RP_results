//===========================================================
//                 MACRO TO MAKE NTUPLE PLOTS
//===========================================================

void make_NTuple_plots_genie_Nu(){

  // Get file and TTree
  TFile *file1 = new TFile("SupernovaAna_genie_hist.root");
  gDirectory->cd("supernovaana");
  TTree *tree1 = (TTree*)gDirectory->Get("SupernovaAna");
  //tree1->SetMarkerStyle();

  // Create cuts
  TCut NuEnergyGT0 = "NuEnergyTruths >= 0.0";
  TCut NuEnergyLT10 = "NuEnergyTruths < 10.0";
  TCut NHitsLT2 = "NHits <=2.0";
  TCut NHitsLT20 = "NHits <=20.0";
  TCut NHitsGT20 = "NHits >=20.0";

  // Create Fits
  TF1 *Poisson1 = new TF1("Poisson1","[0]*TMath::Poisson(x,[1])",0,50);
  TF1 *Poisson2 = new TF1("Poisson2","[0]*TMath::Power(([1]/[2]),(x/[2]))*(TMath::Exp(-([1]/[2])))/TMath::Gamma((x/[2])+1)",0.0,0.1); //last two are xmin and xmax

  // Create histograms
  TH1F *hNMCTruths = new TH1F("hNMCTruths","Number of MC truths per events;N MC truths;Count",100,-0.5,100.5);
  TCanvas *cNMCTruths = new TCanvas("cNMCTruths","NMCTruths");
  cNMCTruths->cd();
  tree1->Draw("NMCTruths >> hNMCTruths");
  hNMCTruths->Draw();
  
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

  TH1F *hThetaTruths = new TH1F("hThetaTruths","Number of MC events at angle #theta;#theta [rad];Count",100,-0.001,0.001);
  TCanvas *cThetaTruths = new TCanvas("cThetaTruths","ThetaTruths");
  cThetaTruths->cd();
  tree1->Draw("ThetaTruths >> hThetaTruths",NuEnergyGT0);
  hThetaTruths->Draw();

  TCanvas *cLeptonEnergyV = new TCanvas("cVLeptonEnergyV","VLeptonEnergyV");
  cLeptonEnergyV->Divide(2,1);
  cLeptonEnergyV->cd(1);
  TH2F *hLeptonEnergyVNHits = new TH2F("hLeptonEnergyVNHits"," Lepton Energy against number of hits; N hits ;Lepton Energy [GeV]",101,-0.5,100.5,101,-0.0,0.088);
  tree1->Draw("LeptonEnergyTruths:NHits >> hLeptonEnergyVNHits",NuEnergyGT0);
  hLeptonEnergyVNHits->Draw("colz");
  cLeptonEnergyV->cd(2);
  TH2F *hLeptonEnergyVSummedADC = new TH2F("hLeptonEnergyVSummedADC","Lepton Energy against Summed ADC;Summed ADC [Volt seconds?] ;Lepton Energy [GeV]",100,0.0,25e3,101,-0.0,0.088);
  tree1->Draw("LeptonEnergyTruths:SummedADC >> hLeptonEnergyVSummedADC",NuEnergyGT0);
  hLeptonEnergyVSummedADC->Draw("colz");
  
  TCanvas *cDetectorAngleV = new TCanvas("cDetectorAngleVNHits","DetectorAngleVNHits");
  cDetectorAngleV->Divide(2,1);
  cDetectorAngleV->cd(1);
  TH2F *hDetectorAngleVNHits = new TH2F("hDetectorAngleVNHits","Detector angle against number of hits; N hits;Detector angle",101,-0.5,100.5,101,-2.0,2.0);
  tree1->Draw("TMath::ATan(MomentumYTruths/MomentumZTruths):NHits >> hDetectorAngleVNHits",NuEnergyGT0);
  hDetectorAngleVNHits->Draw("colz");
  cDetectorAngleV->cd(2);
   TH2F *hDetectorAngleVSummedADC = new TH2F("hDetectorAngleVSummedADC","Detector angle against summed ADC; Summed ADC;Detector angle",101,0,25e3,101,-2.0,2.0);
  tree1->Draw("TMath::ATan(MomentumYTruths/MomentumZTruths):SummedADC >> hDetectorAngleVSummedADC",NuEnergyGT0);
  hDetectorAngleVSummedADC->Draw("colz");

  TCanvas *cYZVertex = new TCanvas("cYZVertex","YZVertex");
  cYZVertex->Divide(2,2);
  cYZVertex->cd(1);
  TH2F *hYZVertex1 = new TH2F("hYZVertex1","Number of particles in y-z plane for all hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("yTruths:zTruths >> hYZVertex1");
  hYZVertex1->Draw("colz");
  cYZVertex->cd(2);
  TH2F *hYZVertex2 = new TH2F("hYZVertex2","Number of particles in y-z plane with more than twenty hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("yTruths:zTruths >> hYZVertex2",NHitsGT20);
  hYZVertex2->Draw("colz");
  cYZVertex->cd(3);
  TH2F *hYZVertex3 = new TH2F("hYZVertex3","Number of particles in y-z plane with less than twenty hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("yTruths:zTruths >> hYZVertex3",NHitsLT20);
  hYZVertex3->Draw("colz");
  cYZVertex->cd(4);
  TH2F *hYZVertex4 = new TH2F("hYZVertex4","Number of particles in y-z plane with less than two hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("yTruths:zTruths >> hYZVertex4",NHitsLT2);
  hYZVertex4->Draw("colz");

  TCanvas *cXYVertex = new TCanvas("cXYVertex","XYVertex");
  cXYVertex->Divide(2,2);
  cXYVertex->cd(1);
  TH2F *hXYVertex1 = new TH2F("hXYVertex1","Number of particles in x-y plane for all hits;y;x",100,-100,600,100,-700,700);
  tree1->Draw("xTruths:yTruths >> hXYVertex1");
  hXYVertex1->Draw("colz");
  cXYVertex->cd(2);
  TH2F *hXYVertex2 = new TH2F("hXYVertex2","Number of particles in x-y plane with more than twenty hits;y;x",100,-650,650,100,-450,450);
  tree1->Draw("xTruths:yTruths >> hXYVertex2",NHitsGT20);
  hXYVertex2->Draw("colz");
  cXYVertex->cd(3);
  TH2F *hXYVertex3 = new TH2F("hXYVertex3","Number of particles in x-y plane with less than twenty hits;y;x",100,-100,600,100,-700,700);
  tree1->Draw("xTruths:yTruths >> hXYVertex3",NHitsLT20);
  hXYVertex3->Draw("colz");
  cXYVertex->cd(4);
  TH2F *hXYVertex4 = new TH2F("hXYVertex4","Number of particles in x-y plane with less than two hits;y;x",100,-100,600,100,-700,700);
  tree1->Draw("xTruths:yTruths >> hXYVertex4",NHitsLT2);
  hXYVertex4->Draw("colz");

  TCanvas *cXZVertex = new TCanvas("cXZVertex","XZVertex");
  cXZVertex->Divide(2,2);
  cXZVertex->cd(1);
  TH2F *hXZVertex1 = new TH2F("hXZVertex1","Number of particles in x-z plane for all hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("xTruths:zTruths >> hXZVertex1");
  hXZVertex1->Draw("colz");
  cXZVertex->cd(2);
  TH2F *hXZVertex2 = new TH2F("hXZVertex2","Number of particles in x-z plane with more than twenty hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("xTruths:zTruths >> hXZVertex2",NHitsGT20);
  hXZVertex2->Draw("colz");
  cXZVertex->cd(3);
  TH2F *hXZVertex3 = new TH2F("hXZVertex3","Number of particles in x-z plane with less than twenty hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("xTruths:zTruths >> hXZVertex3",NHitsLT20);
  hXZVertex3->Draw("colz");
  cXZVertex->cd(4);
  TH2F *hXZVertex4 = new TH2F("hXZVertex4","Number of particles in x-z plane with less than two hits;z;y",100,-100,600,100,-700,700);
  tree1->Draw("xTruths:zTruths >> hXZVertex4",NHitsLT2);
  hXZVertex4->Draw("colz");

  TCanvas *cEventNumV = new TCanvas("cEventNumV","EventNumV");
  cEventNumV->Divide(2,1);
  cEventNumV->cd(1);
  TH2F *hEventNumVNHits1 = new TH2F("hEventNumVNHits1","Event Number vs Number of hits;N hits; Event number",10,0,500,1001,-0.5,1000.5);
  tree1->Draw("EventNum:NHits >> hEventNumVNHits1");
  hEventNumVNHits1->Draw("colz");
  cEventNumV->cd(2);
  TH2F *hEventNumVNHits2 = new TH2F("hEventNumVNHits2","Event Number vs Number of hits with ;N hits; Event number",10,0,500,1001,-0.5,1000.5);
  tree1->Draw("EventNum:NHits >> hEventNumVNHits2",NHitsLT2);
  hEventNumVNHits2->Draw("colz");


  

}
