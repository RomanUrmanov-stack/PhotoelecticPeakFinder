{
    TFile *f1 = TFile::Open("Thread_Ce_G500_T10.root");
    TH1 *temp1 = (TH1*)Amplitude->Clone();
    int start = temp1->FindFirstBinAbove(0,1);
    int count = 4;
    double norm = 0;
    for (int i = 0; i < count; i++)
    {
        norm = norm + temp1->GetBinContent(start+i);
    }
    norm = 1/(norm/count);
    temp1->Scale(norm);    

    TFile *f2 = TFile::Open("Thread_Cs137_Ce_G500_T10.root");
    TH1 *temp2 = (TH1*)Amplitude->Clone();
    start = temp2->FindFirstBinAbove(0,1);
    norm = 0;
    for (int i = 0; i < count; i++)
    {
        norm = norm + temp2->GetBinContent(start+i);
    }
    norm = 1/(norm/count);
    temp2->Scale(norm);
    

    temp1->Add(temp1, temp2, -1, 1);
    temp2->Draw();
    system("pause");
} 