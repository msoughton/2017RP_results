{
//=========Macro generated from canvas: Canvas_1_n2/Canvas_1_n2
//=========  (Wed Jul 20 07:15:24 2016) by ROOT version5.34/32
   TCanvas *Canvas_1_n2 = new TCanvas("Canvas_1_n2", "Canvas_1_n2",1067,254,538,323);
   Canvas_1_n2->Range(-0.4908738,-24.01875,3.632466,216.1688);
   Canvas_1_n2->SetFillColor(0);
   Canvas_1_n2->SetBorderMode(0);
   Canvas_1_n2->SetBorderSize(2);
   Canvas_1_n2->SetFrameBorderMode(0);
   Canvas_1_n2->SetFrameBorderMode(0);
   
   TH1F *fThetaTruths = new TH1F("fThetaTruths","Number of interactions with an angle of #theta between incoming neutrino and outgoing lepton",40,-0.07853982,3.220132);
   fThetaTruths->SetBinContent(2,183);
   fThetaTruths->SetBinContent(3,176);
   fThetaTruths->SetBinContent(4,170);
   fThetaTruths->SetBinContent(5,129);
   fThetaTruths->SetBinContent(6,106);
   fThetaTruths->SetBinContent(7,66);
   fThetaTruths->SetBinContent(8,38);
   fThetaTruths->SetBinContent(9,41);
   fThetaTruths->SetBinContent(10,30);
   fThetaTruths->SetBinContent(11,28);
   fThetaTruths->SetBinContent(12,24);
   fThetaTruths->SetBinContent(13,24);
   fThetaTruths->SetBinContent(14,13);
   fThetaTruths->SetBinContent(15,11);
   fThetaTruths->SetBinContent(16,16);
   fThetaTruths->SetBinContent(17,4);
   fThetaTruths->SetBinContent(18,9);
   fThetaTruths->SetBinContent(19,3);
   fThetaTruths->SetBinContent(20,9);
   fThetaTruths->SetBinContent(21,2);
   fThetaTruths->SetBinContent(22,2);
   fThetaTruths->SetBinContent(23,3);
   fThetaTruths->SetBinContent(24,3);
   fThetaTruths->SetBinContent(25,3);
   fThetaTruths->SetBinContent(26,1);
   fThetaTruths->SetBinContent(28,2);
   fThetaTruths->SetBinContent(29,1);
   fThetaTruths->SetBinContent(34,1);
   fThetaTruths->SetBinContent(36,2);
   fThetaTruths->SetEntries(1100);
   
   TPaveStats *ptstats = new TPaveStats(0.7798507,0.6902357,0.9794776,0.9360269,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *text = ptstats->AddText("fThetaTruths");
   text->SetTextSize(0.03768799);
   text = ptstats->AddText("Entries = 1100   ");
   text = ptstats->AddText("Mean  =  0.389");
   text = ptstats->AddText("RMS   = 0.3918");
   text = ptstats->AddText("Underflow =      0");
   text = ptstats->AddText("Overflow  =      0");
   ptstats->SetOptStat(111111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   fThetaTruths->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(fThetaTruths);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   fThetaTruths->SetLineColor(ci);
   fThetaTruths->GetXaxis()->SetTitle("#theta [rad]");
   fThetaTruths->GetXaxis()->SetLabelFont(42);
   fThetaTruths->GetXaxis()->SetLabelSize(0.035);
   fThetaTruths->GetXaxis()->SetTitleSize(0.035);
   fThetaTruths->GetXaxis()->SetTitleFont(42);
   fThetaTruths->GetYaxis()->SetTitle("count");
   fThetaTruths->GetYaxis()->SetLabelFont(42);
   fThetaTruths->GetYaxis()->SetLabelSize(0.035);
   fThetaTruths->GetYaxis()->SetTitleSize(0.035);
   fThetaTruths->GetYaxis()->SetTitleFont(42);
   fThetaTruths->GetZaxis()->SetLabelFont(42);
   fThetaTruths->GetZaxis()->SetLabelSize(0.035);
   fThetaTruths->GetZaxis()->SetTitleSize(0.035);
   fThetaTruths->GetZaxis()->SetTitleFont(42);
   fThetaTruths->Draw("");
   
   TPaveText *pt = new TPaveText(0.15,0.9351869,0.85,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   text = pt->AddText("Number of interactions with an angle of #theta between incoming neutrino and outgoing lepton");
   pt->Draw();
   Canvas_1_n2->Modified();
   Canvas_1_n2->cd();
   Canvas_1_n2->SetSelected(Canvas_1_n2);
}
