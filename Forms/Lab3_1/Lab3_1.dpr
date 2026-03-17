Program Lab3_1;

Uses
    Vcl.Forms,
    Unit1 In 'Unit1.pas' {MainForm} ,
    Unit2 In 'Unit2.pas' {GuideForm};

{$R *.res}

Begin
    Application.Initialize;
    Application.MainFormOnTaskbar := True;
    Application.CreateForm(TMainForm, MainForm);
    Application.Run;

End.
