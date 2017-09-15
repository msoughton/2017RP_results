void test_pads(){

  // Get file and TTree
  TFile *file1 = new TFile("SupernovaAna_1_hist.root");
  gDirectory->cd("supernovaana");
  TTree *tree1 = (TTree*)gDirectory->Get("SupernovaAna");
  //tree1->SetMarkerStyle();

  // Create cuts
  TCut NuEnergyGT0 = "NuEnergyTruths >= 0.0";
  TCut NuEnergyLT10 = "NuEnergyTruths < 10.0";
  // Insert number when files run
  //TCut NHitsLTNUMBER = "NHits <=";
  //TCut NHitsGTNUMBEr = "NHits >=";

  //TPad *pPDGCodeTruths = new TPad("PDGCodeTruths","",0.6,0.2,0.9,0.5);
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
}
