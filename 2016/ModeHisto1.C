{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Jul 20 09:28:13 2016) by ROOT version5.34/32
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",549,114,538,323);
   Canvas_1->Range(-2.25,-82.95001,15.25,746.55);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *fModeTruths = new TH1F("fModeTruths","Number of interaction types",14,-0.5,13.5);
   fModeTruths->SetBinContent(1,175);
   fModeTruths->SetBinContent(2,285);
   fModeTruths->SetBinContent(3,632);
   fModeTruths->SetBinContent(4,8);
   fModeTruths->SetEntries(1100);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("fModeTruths");
   text->SetTextSize(0.0368);
   text = ptstats->AddText("Entries = 1100   ");
   text = ptstats->AddText("Mean  =   1.43");
   text = ptstats->AddText("RMS   = 0.7601");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   fModeTruths->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(fModeTruths);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   fModeTruths->SetLineColor(ci);
   fModeTruths->GetXaxis()->SetTitle("mode");
   fModeTruths->GetXaxis()->SetLabelFont(42);
   fModeTruths->GetXaxis()->SetLabelSize(0.035);
   fModeTruths->GetXaxis()->SetTitleSize(0.035);
   fModeTruths->GetXaxis()->SetTitleFont(42);
   fModeTruths->GetYaxis()->SetTitle("count");
   fModeTruths->GetYaxis()->SetLabelFont(42);
   fModeTruths->GetYaxis()->SetLabelSize(0.035);
   fModeTruths->GetYaxis()->SetTitleSize(0.035);
   fModeTruths->GetYaxis()->SetTitleFont(42);
   fModeTruths->GetZaxis()->SetLabelFont(42);
   fModeTruths->GetZaxis()->SetLabelSize(0.035);
   fModeTruths->GetZaxis()->SetTitleSize(0.035);
   fModeTruths->GetZaxis()->SetTitleFont(42);
   fModeTruths->Draw("");
   
   pt = new TPaveText(0.4067164,0.3068536,0.6791045,0.9018692,"brNDC");
   pt->SetTextSize(0.04);
   text = pt->AddText("0: QE");
   text = pt->AddText("1: Res");
   text = pt->AddText("2: DIS");
   text = pt->AddText("3: Coh");
   text = pt->AddText("4: CohElastic");
   text = pt->AddText("5: Electron scattering");
   text = pt->AddText("6: IMDAnnihilation");
   text = pt->AddText("7: Inverse beta decay");
   text = pt->AddText("8: Glashow resonance");
   text = pt->AddText("9: AMNuGamma");
   text = pt->AddText("10: MEC");
   text = pt->AddText("11: Diffractive");
   text = pt->AddText("12: EM");
   text = pt->AddText("13: Weak mix");
   pt->Draw();

   TPaveText *pt = new TPaveText(0.291306,0.9351869,0.708694,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Number of interaction types");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
