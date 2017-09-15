//===========================================================
//                 MACRO TO MAKE NTUPLE PLOTS
//===========================================================

void make_NTuple_plots_20_Nu(){

  // Get file and TTree
  TFile *file1 = new TFile("SupernovaAna_20_hist.root");
  gDirectory->cd("supernovaana");
  TTree *tree1 = (TTree*)gDirectory->Get("SupernovaAna");
  //tree1->SetMarkerStyle();

  // Create cuts
  TCut NuEnergyGT0 = "NuEnergyTruths >= 0.0";
  TCut NuEnrgyLT10 = "NuEnergyTruths < 10.0";
  TCut NHitsLT2 = "NHits <=2";
  TCut NHitsLT20 = "NHits <=20";
  TCut NHitsGT20 = "NHits >=20";

  // Create Fits
  TF1 *Poisson1 = new TF1("Poisson1","[0]*TMath::Poisson(x,[1])",0,50);
  TF1 *Poisson2 = new TF1("Poisson2","[0]*TMath::Power(([1]/[2]),(x/[2]))*(TMath::Exp(-([1]/[2])))/TMath::Gamma((x/[2])+1)",0.0,0.1); //last two are xmin and xmax
  

  // Create histograms on seperate canvases 
  TCanvas *cNMCTruths = new TCanvas("cNMCTruths","NMCTruths");
  cNMCTruths->cd();
  TH1F *hNMCTruths = new TH1F("hNMCTruths","Number of MC truths per events;N MC truths;Count",100,-0.5,100.5);
  tree1->Draw("NMCTruths >> hNMCTruths");
  hNMCTruths->Draw();
  Poisson1->SetParameters(2,20);
  hNMCTruths->Fit("Poisson1");
  
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


}
