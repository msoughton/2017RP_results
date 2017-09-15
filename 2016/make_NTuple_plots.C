//===========================================================
//                 MACRO TO MAKE NTUPLE PLOTS
//===========================================================

void make_NTuple_plots(){

  // Get file and TTree
  TFile *file1 = new TFile("SupernovaAna_1_hist.root");
  gDirectory->cd("supernovaana");
  TTree *tree1 = (TTree*)gDirectory->Get("SupernovaAna");
  //tree1->SetMarkerStyle();

  // Create cuts
  TCut energyGT0 = "EnergyTruths >= 0.0";
  TCut energyLT10 = "EnergyTruths < 10.0";

  // Create histograms
  TH2F *hNMCTruthsVNHits = new TH2F("hNMCTruthsVNHits","Number of MC truths against number of hits ;N Hits;N MC Truths",101,-0.5,100.5,11,-0.5,10.5);
  TCanvas *cNMCTruthsVNHits = new TCanvas("cNMCTruthsVNHits","NMCTruthsVNHits");
  cNMCTruthsVNHits->cd();
  tree1->Draw("NMCTruths:NHits >> hNMCTruthsVNHits");
  hNMCTruthsVNHits->Draw("colz");

  TH2F *hNMCTruthsVSummedADC = new TH2F("hNMCTruthsVSummedADC","Number of MC truths against summed ADC ;Summed ADC;N MC Truths",21,-10.5,10.5,11,-0.5,10.5);
  TCanvas *cNMCTruthsVSummedADC = new TCanvas("cNMCTruthsVSummedADC","NMCTruthsVSummedADC");
  cNMCTruthsVSummedADC->cd();
  tree1->Draw("NMCTruths:SummedADC >> hNMCTruthsVSummedADC");
  hNMCTruthsVSummedADC->Draw("colz");

  

  

  

}
