{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Thu Jul 21 08:00:19 2016) by ROOT version5.34/32
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",408,104,538,323);
   Canvas_1->Range(-0.7494173,149.4784,1.749417,907.0509);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetTopMargin(0.07165109);
   Canvas_1->SetBottomMargin(0.1308411);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *fCCNCTruths = new TH1F("fCCNCTruths","Number of Charged Current and Neutral Current interactions",2,-0.5,1.5);
   fCCNCTruths->SetBinContent(1,824);
   fCCNCTruths->SetBinContent(2,276);
   fCCNCTruths->SetEntries(1100);
   
   TPaveStats *ptstats = new TPaveStats(0.7033582,0.7632399,0.9029851,0.9252336,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("fCCNCTruths");
   text->SetTextSize(0.03725857);
   text = ptstats->AddText("Entries = 1100   ");
   text = ptstats->AddText("Mean  = 0.2509");
   text = ptstats->AddText("RMS   = 0.4335");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   fCCNCTruths->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(fCCNCTruths);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   fCCNCTruths->SetLineColor(ci);
   fCCNCTruths->GetXaxis()->SetTitle("CC or NC");
   fCCNCTruths->GetXaxis()->SetLabelFont(42);
   fCCNCTruths->GetXaxis()->SetLabelSize(0.035);
   fCCNCTruths->GetXaxis()->SetTitleSize(0.035);
   fCCNCTruths->GetXaxis()->SetTitleFont(42);
   fCCNCTruths->GetYaxis()->SetTitle("count");
   fCCNCTruths->GetYaxis()->SetLabelFont(42);
   fCCNCTruths->GetYaxis()->SetLabelSize(0.035);
   fCCNCTruths->GetYaxis()->SetTitleSize(0.035);
   fCCNCTruths->GetYaxis()->SetTitleFont(42);
   fCCNCTruths->GetZaxis()->SetLabelFont(42);
   fCCNCTruths->GetZaxis()->SetLabelSize(0.035);
   fCCNCTruths->GetZaxis()->SetTitleSize(0.035);
   fCCNCTruths->GetZaxis()->SetTitleFont(42);
   fCCNCTruths->Draw("");
   
   TPaveText *pt = new TPaveText(0.15,0.9351869,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Number of Charged Current and Neutral Current interactions");
   pt->Draw();
   
   pt = new TPaveText(0.7014925,0.6292835,0.8208955,0.7507788,"brNDC");
   pt->SetFillColor(0);
   pt->SetTextSize(0.04);
   text = pt->AddText("0: CC");
   text = pt->AddText("1: NC");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
