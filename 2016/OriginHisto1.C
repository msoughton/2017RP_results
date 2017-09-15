{
//=========Macro generated from canvas: Canvas_1/Canvas_1
//=========  (Wed Jul 20 09:47:44 2016) by ROOT version5.34/32
   TCanvas *Canvas_1 = new TCanvas("Canvas_1", "Canvas_1",388,126,538,323);
   Canvas_1->Range(-2.245921,-189.2647,15.24592,1252.059);
   Canvas_1->SetFillColor(0);
   Canvas_1->SetBorderMode(0);
   Canvas_1->SetBorderSize(2);
   Canvas_1->SetTopMargin(0.06734007);
   Canvas_1->SetBottomMargin(0.1313131);
   Canvas_1->SetFrameBorderMode(0);
   Canvas_1->SetFrameBorderMode(0);
   
   TH1F *fOriginTruths = new TH1F("fOriginTruths","Number of neutrinos from each source (see Origin documentation)",14,-0.5,13.5);
   fOriginTruths->SetBinContent(2,1100);
   fOriginTruths->SetEntries(1100);
   
   TPaveStats *ptstats = new TPaveStats(0.6996269,0.7383178,0.8992537,0.9003115,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("fOriginTruths");
   text->SetTextSize(0.03725855);
   text = ptstats->AddText("Entries = 1100   ");
   text = ptstats->AddText("Mean  =      1");
   text = ptstats->AddText("RMS   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   fOriginTruths->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(fOriginTruths);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   fOriginTruths->SetLineColor(ci);
   fOriginTruths->GetXaxis()->SetTitle("source");
   fOriginTruths->GetXaxis()->SetLabelFont(42);
   fOriginTruths->GetXaxis()->SetLabelSize(0.035);
   fOriginTruths->GetXaxis()->SetTitleSize(0.035);
   fOriginTruths->GetXaxis()->SetTitleFont(42);
   fOriginTruths->GetYaxis()->SetTitle("count");
   fOriginTruths->GetYaxis()->SetLabelFont(42);
   fOriginTruths->GetYaxis()->SetLabelSize(0.035);
   fOriginTruths->GetYaxis()->SetTitleSize(0.035);
   fOriginTruths->GetYaxis()->SetTitleFont(42);
   fOriginTruths->GetZaxis()->SetLabelFont(42);
   fOriginTruths->GetZaxis()->SetLabelSize(0.035);
   fOriginTruths->GetZaxis()->SetTitleSize(0.035);
   fOriginTruths->GetZaxis()->SetTitleFont(42);
   fOriginTruths->Draw("");
   
   TPaveText *pt = new TPaveText(0.15,0.9351869,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Number of neutrinos from each source (see Origin documentation)");
   pt->Draw();
   
   pt = new TPaveText(0.4067164,0.6094276,0.6791045,0.9023569,"brNDC");
   pt->SetTextSize(0.04);
   text = pt->AddText("0: Unknown");
   text = pt->AddText("1: Beam");
   text = pt->AddText("2: Cosmic rays");
   text = pt->AddText("3: Supernova neutrinos");
   text = pt->AddText("4: Single particles");
   pt->Draw();
   Canvas_1->Modified();
   Canvas_1->cd();
   Canvas_1->SetSelected(Canvas_1);
}
