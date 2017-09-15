//===========================================================
//                 MACRO TO MAKE NTUPLE PLOTS
//===========================================================

void make_NTuple_plots_1_Nu_1D(){

  // Get file and TTree
  TFile *file1 = new TFile("SupernovaAna_1_hist.root");
  gDirectory->cd("supernovaana");
  TTree *tree1 = (TTree*)gDirectory->Get("SupernovaAna");
  //tree1->SetMarkerStyle();

  // Create cuts
  TCut NuEnergyGT0 = "NuEnergyTruths >= 0.0";
  TCut NuEnergyLT10 = "NuEnergyTruths < 10.0";
  TCut NHits0 = "NHits < 1";
  TCut NHitsGT0 = "NHits > 0";

  // Create Fits
  TF1 *Poisson1 = new TF1("Poisson1","[0]*TMath::Poisson(x,[1])",0,50);
  TF1 *Poisson2 = new TF1("Poisson2","[0]*TMath::Power(([1]/[2]),(x/[2]))*(TMath::Exp(-([1]/[2])))/TMath::Gamma((x/[2])+1)",0.0,0.1); //last two are xmin and xmax

  // Create histograms
  TCanvas *cEventNum = new TCanvas("cEventNum","EventNumV");
  cEventNum->Divide(2,1);
  cEventNum->cd(1);
  TH1F *hEventNum1 = new TH1F("hEventNum1","Event Number with N hits greater than zero;Event number; Count",1001,-0.5,1000.5);
  tree1->Draw("EventNum >> hEventNum1",NHitsGT0);
  hEventNum1->Draw("colz");
  cEventNum->cd(2);
  TH1F *hEventNum2 = new TH1F("hEventNum2","Event Number with N hits equal to zero;Event number; Count",1001,-0.5,1000.5);
  tree1->Draw("EventNum >> hEventNum2",NHits0);
  hEventNum2->Draw("colz");

  TCanvas *cNMCTruths = new TCanvas("cNMCTruths","NMCTruths");
  cNMCTruths->Divide(2,1);
  cNMCTruths->cd(1);
  TH1F *hNMCTruths1 = new TH1F("hNMCTruths1","Number of MC truths per events with N hits greater than zero;N MC truths;Count",100,-0.5,100.5);
  tree1->Draw("NMCTruths >> hNMCTruths1",NHitsGT0);
  hNMCTruths1->Draw();
  cNMCTruths->cd(2);
  TH1F *hNMCTruths2 = new TH1F("hNMCTruths2","Number of MC truths per event with N hits equal to zero;N MC truths;Count",100,-0.5,100.5);
  tree1->Draw("NMCTruths >> hNMCTruths2",NHits0);
  hNMCTruths2->Draw();

  TCanvas *cNHits = new TCanvas("cNHits","NHits");
  cNHits->Divide(2,1);
  cNHits->cd(1);
  TH1F *hNHits1 = new TH1F("hNHits1","Number of hits per events with N hits greater than zero;N hits;Count",100,-0.5,100.5);
  tree1->Draw("NHits >> hNHits1",NHitsGT0);
  hNHits1->Draw();
  cNHits->cd(2);
  TH1F *hNHits2 = new TH1F("hNHits2","Number of hits per event with N hits equal to zero;N hits;Count",100,-0.5,100.5);
  tree1->Draw("NHits >> hNHits2",NHits0);
  hNHits2->Draw();

  TCanvas *cSummedADC = new TCanvas("cSummedADC","SummedADC");
  cSummedADC->Divide(2,1);
  cSummedADC->cd(1);
  TH1F *hSummedADC = new TH1F("hSummedADC1","Summed ADC with N hits greater than zero;SummedADC;Count",100,0.0,25e3);
  tree1->Draw("SummedADC >> hSummedADC1",NHitsGT0);
  hSummedADC->Draw();
  cSummedADC->cd(2);
  TH1F *hSummedADC2 = new TH1F("hSummedADC2","Summed ADC with N hits equal to zero;SummedADC;Count",100,0.0,25e3);
  tree1->Draw("SummedADC >> hSummedADC2",NHits0);
  hSummedADC2->Draw();

  TCanvas *cavgRMS = new TCanvas("cavgRMS","avgRMS");
  cavgRMS->Divide(2,1);
  cavgRMS->cd(1);
  TH1F *havgRMS1 = new TH1F("havgRMS1","Average RMS of hit slope with N hits greater than zero;Avg RMS;Count",100,-0.5,100.5);
  tree1->Draw("avgRMS >> havgRMS1",NHitsGT0);
  havgRMS1->Draw();
  cavgRMS->cd(2);
  TH1F *havgRMS2 = new TH1F("havgRMS2","Average RMS of hit slope with N hits equal to zero;Avg RMS;Count",100,-0.5,100.5);
  tree1->Draw("avgRMS >> havgRMS2",NHits0);
  havgRMS2->Draw();

  TCanvas *cOriginTruths = new TCanvas("cOriginTruths","OriginTruths");
  cOriginTruths->Divide(2,1);
  cOriginTruths->cd(1);
  TH1F *hOriginTruths1 = new TH1F("hOriginTruths1","Origin Truths with N hits greater than zero;Origin Truths;Count",5,-0.5,4.5);
  tree1->Draw("OriginTruths >> hOriginTruths1",NHitsGT0);
  hOriginTruths1->Draw();
  cOriginTruths->cd(2);
  TH1F *hOriginTruths2 = new TH1F("hOriginTruths2","Origin Truths with N hits equal to zero;Origin Truths;Count",5,-0.5,4.5);
  tree1->Draw("OriginTruths >> hOriginTruths2",NHits0);
  hOriginTruths2->Draw();

  TCanvas *cCCNCTruths = new TCanvas("cCCNCTruths","CCNCTruths");
  cCCNCTruths->Divide(2,1);
  cCCNCTruths->cd(1);
  TH1F *hCCNCTruths1 = new TH1F("hCCNCTruths1","CCNC Truths with N hits greater than zero;CC or NC;Count",2,-0.5,1.5);
  tree1->Draw("CCNCTruths >> hCCNCTruths1",NHitsGT0);
  hCCNCTruths1->Draw();
  cCCNCTruths->cd(2);
  TH1F *hCCNCTruths2 = new TH1F("hCCNCTruths2","CCNC Truths with N hits equal to zero;CC or NC;Count",2,-0.5,1.5);
  tree1->Draw("CCNCTruths >> hCCNCTruths2",NHits0);
  hCCNCTruths2->Draw();

  TCanvas *cModeTruths = new TCanvas("cModeTruths","ModeTruths");
  cModeTruths->Divide(2,1);
  cModeTruths->cd(1);
  TH1F *hModeTruths1 = new TH1F("hModeTruths1","Mode Truths with N hits greater than zero;Mode of interaction;Count",14,-0.5,13.5);
  tree1->Draw("ModeTruths >> hModeTruths1",NHitsGT0);
  hModeTruths1->Draw();
  cModeTruths->cd(2);
  TH1F *hModeTruths2 = new TH1F("hModeTruths2","Mode Truths with N hits greater than zero;Mode of interaction;Count",14,-0.5,13.5);
  tree1->Draw("ModeTruths >> hModeTruths2",NHits0);
  hModeTruths2->Draw();

  TCanvas *cPDGCodeTruths = new TCanvas("cPDGCodeTruths","PDGCodeTruths");
  cPDGCodeTruths->Divide(2,2);
  cPDGCodeTruths->cd(1);
  TH1F *hNuPDGCodeTruths1 = new TH1F("hNuPDGCodeTruths1","Number of neutrino MC events of specific PDG code with N hits greater than zero;PDG code;Count",37,-18.5,18.5);
  tree1->Draw("NuPDGCodeTruths >> hNuPDGCodeTruths1",NHitsGT0);
  hNuPDGCodeTruths1->Draw();
  cPDGCodeTruths->cd(2);
  TH1F *hNuPDGCodeTruths2 = new TH1F("hNuPDGCodeTruths2","Number of neutrino MC events of specific PDG code with N hits equal to zero;PDG code;Count",37,-18.5,18.5);
  tree1->Draw("NuPDGCodeTruths >> hNuPDGCodeTruths2",NHits0);
  hNuPDGCodeTruths2->Draw();
  cPDGCodeTruths->cd(3);
  TH1F *hLeptonPDGCodeTruths1 = new TH1F("hLeptonPDGCodeTruths1","Number of lepton MC events of specific PDG code with N hits greater than zero;PDG code;Count",37,-18.5,18.5);
  tree1->Draw("LeptonPDGCodeTruths >> hLeptonPDGCodeTruths1",NHitsGT0);
  hLeptonPDGCodeTruths1->Draw();
  cPDGCodeTruths->cd(4);
  TH1F *hLeptonPDGCodeTruths2 = new TH1F("hLeptonPDGCodeTruths2","Number of lepton MC events of specific PDG code with N hits equal to zero;PDG code;Count",37,-18.5,18.5);
  tree1->Draw("LeptonPDGCodeTruths >> hLeptonPDGCodeTruths2",NHits0);
  hLeptonPDGCodeTruths2->Draw();
  
  TCanvas *cEnergyTruths = new TCanvas("cEnergyTruths","EnergyTruths");
  cEnergyTruths->Divide(2,2);
  cEnergyTruths->cd(1);
  TH1F *hNuEnergyTruths1 = new TH1F("hNuEnergyTruths1","Number of MC events of specific neutrino Energy with N hits greater than zero;Nuetrino Energy [GeV];Count",81,-0.001,0.081);
  tree1->Draw("NuEnergyTruths >> hNuEnergyTruths1",NHitsGT0);
  hNuEnergyTruths1->Draw();
  cEnergyTruths->cd(2);
  TH1F *hNuEnergyTruths2 = new TH1F("hNuEnergyTruths2","Number of MC events of specific neutrino Energy with N hits equal to zero;Nuetrino Energy [GeV];Count",81,-0.001,0.081);
  tree1->Draw("NuEnergyTruths >> hNuEnergyTruths2",NHits0);
  hNuEnergyTruths2->Draw();
  cEnergyTruths->cd(3);
  TH1F *hLeptonEnergyTruths1 = new TH1F("hLeptonEnergyTruths1","Number of MC events of specific lepton Energy with N hits greater than zero;Lepton Energy [GeV];Count",81,-0.001,0.081);
  tree1->Draw("LeptonEnergyTruths >> hLeptonEnergyTruths1",NHitsGT0);
  hLeptonEnergyTruths1->Draw(); 
  cEnergyTruths->cd(4);
  TH1F *hLeptonEnergyTruths2 = new TH1F("hLeptonEnergyTruths2","Number of MC events of specific lepton Energy with N hits equal to zero;Lepton Energy [GeV];Count",81,-0.001,0.081);
  tree1->Draw("LeptonEnergyTruths >> hLeptonEnergyTruths2",NHits0);
  hLeptonEnergyTruths2->Draw(); 

  TCanvas *cThetaTruths = new TCanvas("cThetaTruths","ThetaTruths");
  cThetaTruths->Divide(2,1);
  cThetaTruths->cd(1);
  TH1F *hThetaTruths1 = new TH1F("hThetaTruths1","Number of MC events at angle #theta with N hits greater than zero;#theta [rad];Count",100,-0.001,0.001);
  tree1->Draw("ThetaTruths >> hThetaTruths1",NHitsGT0);
  hThetaTruths1->Draw();
  cThetaTruths->cd(2);
  TH1F *hThetaTruths2 = new TH1F("hThetaTruths2","Number of MC events at angle #theta with N hits equal to zero;#theta [rad];Count",100,-0.001,0.001);
  tree1->Draw("ThetaTruths >> hThetaTruths2",NHits0);
  hThetaTruths2->Draw();

  TCanvas *cDetectorAngle = new TCanvas("cDetectorAngle","DetectorAngle");
  cDetectorAngle->Divide(2,1);
  cDetectorAngle->cd(1);
  TH1F *hDetectorAngle1 = new TH1F("hDetectorAngle1","Detector angle with N hits greater than zero;Detector angle;Count",101,-2.0,2.0);
  tree1->Draw("TMath::ATan(MomentumYTruths/MomentumZTruths) >> hDetectorAngle1",NHitsGT0);
  hDetectorAngle1->Draw("colz");
  cDetectorAngle->cd(2);
  TH1F *hDetectorAngle2 = new TH1F("hDetectorAngle2","Detector angle with N hits equal to zero;Detector angle;Count",101,-2.0,2.0);
  tree1->Draw("TMath::ATan(MomentumYTruths/MomentumZTruths) >> hDetectorAngle2",NHits0);
  hDetectorAngle2->Draw("colz");
  

}
