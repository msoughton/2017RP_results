// Plots all branches

void make_NTuple_plots_all_branches(){
  TFile *myfile = new TFile("SupernovaAna_radiological1_hist.root");
  gDirectory->cd("supernovaana");
  TTree* mytree = (TTree*)gDirectory->Get("SupernovaAna");
  
  TObjArray *arr = mytree->GetListOfBranches();

  for(int i=0; i < arr->GetSize();i++)
  {
    // Need an individual canvas for each plot
    // We could just divide the canvas but plots would be too small to see
    //TCanvas canvasName;
    //canvasName += "c"s + std::to_string(i);
    TString branchName = arr->At(i)->GetName();
    TCanvas *canvas = new TCanvas("canvas",branchName);
 
  
    mytree->Draw(branchName);
    canvas->SaveAs(branchName+".pdf");
  }

  
}
