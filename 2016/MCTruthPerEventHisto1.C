{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Jul 20 07:24:49 2016) by ROOT version5.34/32
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",1144,76,538,323);
   Canvas_1->Range(-13.125,-144.375,113.125,1299.375);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *fNMCTruths = new TH1F("fNMCTruths","Number of MCTruths per event",101,-0.5,100.5);
   fNMCTruths->SetBinContent(2,1100);
   fNMCTruths->SetEntries(1100);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("fNMCTruths");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1100   ");
   text = ptstats->AddText("Mean  =      1");
   text = ptstats->AddText("RMS   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   fNMCTruths->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(fNMCTruths);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   fNMCTruths->SetLineColor(ci);
   fNMCTruths->GetXaxis()->SetTitle("N");
   fNMCTruths->GetXaxis()->SetLabelFont(42);
   fNMCTruths->GetXaxis()->SetLabelSize(0.035);
   fNMCTruths->GetXaxis()->SetTitleSize(0.035);
   fNMCTruths->GetXaxis()->SetTitleFont(42);
   fNMCTruths->GetYaxis()->SetTitle("count");
   fNMCTruths->GetYaxis()->SetLabelFont(42);
   fNMCTruths->GetYaxis()->SetLabelSize(0.035);
   fNMCTruths->GetYaxis()->SetTitleSize(0.035);
   fNMCTruths->GetYaxis()->SetTitleFont(42);
   fNMCTruths->GetZaxis()->SetLabelFont(42);
   fNMCTruths->GetZaxis()->SetLabelSize(0.035);
   fNMCTruths->GetZaxis()->SetTitleSize(0.035);
   fNMCTruths->GetZaxis()->SetTitleFont(42);
   fNMCTruths->Draw("");
   
   TPaveText *pt = new TPaveText(0.2707836,0.9351869,0.7292164,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Number of MCTruths per event");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
