program Lab4_4;

uses
  Vcl.Forms,
  Unit1 in '..\..\..\Forms\Lab3_3-\Unit1.pas' {MainForm},
  Unit2 in 'Unit2.pas' {GuideForm};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TMainForm, MainForm);
  Application.Run;
end.
