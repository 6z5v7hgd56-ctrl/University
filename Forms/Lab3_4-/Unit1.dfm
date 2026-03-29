object MainForm: TMainForm
  Left = 0
  Top = 0
  Margins.Left = 5
  Margins.Top = 5
  Margins.Right = 5
  Margins.Bottom = 5
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = '551004 '#1055#1077#1076#1100#1082#1086' '#1042#1083#1072#1076#1080#1089#1083#1072#1074' Lab3.4'
  ClientHeight = 311
  ClientWidth = 812
  Color = clBtnFace
  Constraints.MaxHeight = 450
  Constraints.MaxWidth = 834
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -18
  Font.Name = 'Segoe UI'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  Position = poDesktopCenter
  OnCloseQuery = FormCloseQuery
  OnHelp = FormHelp
  PixelsPerInch = 144
  TextHeight = 25
  object LabelString: TLabel
    Left = 8
    Top = 119
    Width = 67
    Height = 25
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Caption = #1057#1090#1088#1086#1082#1072': '
  end
  object TaskLabel: TLabel
    Left = 8
    Top = 17
    Width = 792
    Height = 81
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    AutoSize = False
    BiDiMode = bdLeftToRight
    Caption = 
      #1055#1088#1086#1075#1088#1072#1084#1084#1072' '#1087#1088#1086#1074#1077#1088#1103#1077#1090', '#1080#1084#1077#1077#1090#1089#1103' '#1083#1080' '#1074' '#1079#1072#1076#1072#1085#1085#1086#1084' '#1090#1077#1082#1089#1090#1077' '#1073#1072#1083#1072#1085#1089' '#1086#1090#1082#1088#1099#1074#1072 +
      #1102#1097#1080#1093' '#1080' '#1079#1072#1082#1088#1099#1074#1072#1102#1097#1080#1093' '#1089#1082#1086#1073#1086#1082
    Constraints.MaxHeight = 750
    Constraints.MaxWidth = 848
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    WordWrap = True
    StyleName = 'Windows'
  end
  object LabelResult: TLabel
    Left = 8
    Top = 240
    Width = 713
    Height = 63
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    AutoSize = False
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -22
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    Visible = False
    WordWrap = True
  end
  object ButtonResult: TButton
    Left = 8
    Top = 178
    Width = 157
    Height = 37
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090
    Enabled = False
    TabOrder = 0
    OnClick = ButtonResultClick
  end
  object EditString: TEdit
    Left = 84
    Top = 116
    Width = 344
    Height = 33
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Ctl3D = True
    MaxLength = 30
    ParentCtl3D = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnChange = EditStringChange
    OnKeyPress = EditStringKeyPress
  end
  object MainMenu1: TMainMenu
    Left = 768
    Top = 182
    object FileTab: TMenuItem
      Caption = #1060#1072#1081#1083
      object OpenTab: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        ShortCut = 16463
        OnClick = OpenTabClick
      end
      object SaveTab: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Enabled = False
        ShortCut = 16467
        OnClick = SaveTabClick
      end
      object Separator1: TMenuItem
        Caption = '-'
      end
      object LeaveTab: TMenuItem
        Caption = #1042#1099#1081#1090#1080
        OnClick = LeaveTabClick
      end
    end
    object InstructionTab: TMenuItem
      Caption = #1048#1085#1089#1090#1088#1091#1082#1094#1080#1103
      OnClick = InstructionTabClick
    end
    object AboutDeveloperTab: TMenuItem
      Caption = #1054' '#1056#1072#1079#1088#1072#1073#1086#1090#1095#1080#1082#1077
      OnClick = AboutDeveloperTabClick
    end
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 968
    Top = 182
  end
  object SaveTextFileDialog1: TSaveTextFileDialog
    Left = 566
    Top = 182
  end
end
