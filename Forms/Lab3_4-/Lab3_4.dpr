Program Lab3_4;

uses
  Vcl.Forms,
  Unit1 in 'Unit1.pas' {MainForm},
  Unit2 in 'Unit2.pas' {GuideForm};

{$R *.res}

Begin
    Application.Initialize;
    Application.MainFormOnTaskbar := True;
    Application.CreateForm(TMainForm, MainForm);
  Application.Run;

End.
