{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Thu Jul 21 07:57:49 2016) by ROOT version5.34/32
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",408,104,538,323);
   Canvas_1->Range(-23.11422,-173.7217,23.11422,1123.131);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetTopMargin(0.06853583);
   Canvas_1->SetBottomMargin(0.1339564);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *fPDGCodeTruths = new TH1F("fPDGCodeTruths","Number of particles of a type",37,-18.5,18.5);
   fPDGCodeTruths->SetBinContent(5,97);
   fPDGCodeTruths->SetBinContent(7,2);
   fPDGCodeTruths->SetBinContent(31,16);
   fPDGCodeTruths->SetBinContent(33,985);
   fPDGCodeTruths->SetEntries(1100);
   
   TPaveStats *ptstats = new TPaveStats(0.1791045,0.6074766,0.3787313,0.9283489,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("fPDGCodeTruths");
   text->SetTextSize(0.04920042);
   text = ptstats->AddText("Entries = 1100   ");
   text = ptstats->AddText("Mean  =  11.45");
   text = ptstats->AddText("RMS   =  7.996");
   text = ptstats->AddText("Underflow =      0");
   text = ptstats->AddText("Overflow  =      0");
   ptstats->SetOptStat(111111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   fPDGCodeTruths->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(fPDGCodeTruths);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   fPDGCodeTruths->SetLineColor(ci);
   fPDGCodeTruths->GetXaxis()->SetTitle("Particle type");
   fPDGCodeTruths->GetXaxis()->SetLabelFont(42);
   fPDGCodeTruths->GetXaxis()->SetLabelSize(0.035);
   fPDGCodeTruths->GetXaxis()->SetTitleSize(0.035);
   fPDGCodeTruths->GetXaxis()->SetTitleFont(42);
   fPDGCodeTruths->GetYaxis()->SetTitle("count");
   fPDGCodeTruths->GetYaxis()->SetLabelFont(42);
   fPDGCodeTruths->GetYaxis()->SetLabelSize(0.035);
   fPDGCodeTruths->GetYaxis()->SetTitleSize(0.035);
   fPDGCodeTruths->GetYaxis()->SetTitleFont(42);
   fPDGCodeTruths->GetZaxis()->SetLabelFont(42);
   fPDGCodeTruths->GetZaxis()->SetLabelSize(0.035);
   fPDGCodeTruths->GetZaxis()->SetTitleSize(0.035);
   fPDGCodeTruths->GetZaxis()->SetTitleFont(42);
   fPDGCodeTruths->Draw("");
   
   TPaveText *pt = new TPaveText(0.2838433,0.9351869,0.7161567,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Number of particles of a type");
   pt->Draw();
   
   pt = new TPaveText(0.1753731,0.4641745,0.6604478,0.6012461,"brNDC");
   pt->SetFillColor(0);
   pt->SetTextSize(0.04);
   text = pt->AddText("See PDG codes at");
   text = pt->AddText("'pdg.lbl.gov/2004/reviews/montecarlorpp.ps'");
   pt->Draw();
   
   pt = new TPaveText(0.1753731,0.4641745,0.6604478,0.6012461,"brNDC");
   pt->SetFillColor(0);
   pt->SetTextSize(0.04);
   text = pt->AddText("See PDG codes at");
   text = pt->AddText("'pdg.lbl.gov/2004/reviews/montecarlorpp.ps'");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
