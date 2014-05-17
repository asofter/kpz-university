object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1055#1086#1073#1091#1076#1086#1074#1072' '#1084#1072#1083#1102#1085#1082#1072' '#1079' '#1092#1110#1075#1091#1088
  ClientHeight = 466
  ClientWidth = 790
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 424
    Top = 16
    Width = 359
    Height = 402
  end
  object Label1: TLabel
    Left = 24
    Top = 19
    Width = 151
    Height = 13
    Caption = #1050#1110#1083#1100#1082#1110#1089#1090#1100' '#1077#1083#1077#1084#1077#1085#1090#1110#1074' '#1084#1072#1083#1102#1085#1082#1072':'
  end
  object SbtnEnterElInMas: TSpeedButton
    Left = 24
    Top = 363
    Width = 201
    Height = 33
    Caption = #1042#1074#1077#1089#1090#1080' '#1077#1083#1077#1084#1077#1085#1090' '#1091' '#1084#1072#1089#1080#1074
    OnClick = SbtnEnterElInMasClick
  end
  object SbtnCreatePicture: TSpeedButton
    Left = 24
    Top = 431
    Width = 385
    Height = 33
    Caption = #1055#1086#1073#1091#1076#1091#1074#1072#1090#1080' '#1084#1072#1083#1102#1085#1086#1082
    OnClick = SbtnCreatePictureClick
  end
  object EdtCountOfElementsInPicture: TEdit
    Left = 192
    Top = 16
    Width = 105
    Height = 21
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 24
    Top = 43
    Width = 201
    Height = 128
    Caption = #1058#1080#1087' '#1077#1083#1077#1084#1077#1085#1090#1072
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 24
      Top = 24
      Width = 158
      Height = 17
      Caption = #1047#1072#1086#1082#1088#1091#1075#1083#1077#1085#1080#1081' '#1087#1088#1103#1084#1086#1082#1091#1090#1085#1080#1082
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 24
      Top = 47
      Width = 113
      Height = 17
      Caption = #1045#1083#1110#1087#1089
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 24
      Top = 70
      Width = 113
      Height = 17
      Caption = #1044#1091#1075#1072
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 24
      Top = 93
      Width = 113
      Height = 17
      Caption = #1050#1074#1072#1076#1088#1072#1090
      TabOrder = 3
      OnClick = RadioButton4Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 24
    Top = 194
    Width = 201
    Height = 121
    Caption = #1047#1072#1075#1072#1083#1100#1085#1110' '#1087#1072#1088#1072#1084#1077#1090#1088#1080
    TabOrder = 2
    object Label2: TLabel
      Left = 11
      Top = 21
      Width = 126
      Height = 13
      Caption = #1042#1080#1073#1110#1088' '#1082#1086#1083#1100#1086#1088#1091' '#1077#1083#1077#1084#1077#1085#1090#1072':'
    end
    object Label3: TLabel
      Left = 11
      Top = 68
      Width = 84
      Height = 13
      Caption = #1058#1077#1082#1089#1090' '#1077#1083#1077#1084#1077#1085#1090#1091':'
    end
    object ColorBox1: TColorBox
      Left = 11
      Top = 40
      Width = 145
      Height = 22
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 11
      Top = 87
      Width = 145
      Height = 21
      TabOrder = 1
    end
  end
  object GroupBox3: TGroupBox
    Left = 240
    Top = 43
    Width = 169
    Height = 102
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1080' '#1087#1088#1103#1084#1086#1082#1091#1090#1085#1080#1082#1072
    TabOrder = 3
    object Label4: TLabel
      Left = 22
      Top = 24
      Width = 52
      Height = 13
      Caption = #1057#1090#1086#1088#1086#1085#1072' 1'
    end
    object Label5: TLabel
      Left = 22
      Top = 51
      Width = 52
      Height = 13
      Caption = #1057#1090#1086#1088#1086#1085#1072' 2'
    end
    object Label12: TLabel
      Left = 11
      Top = 75
      Width = 71
      Height = 13
      Caption = #1047#1072#1086#1082#1088#1091#1075#1083#1077#1085#1085#1103
    end
    object Edit3: TEdit
      Left = 88
      Top = 21
      Width = 70
      Height = 21
      TabOrder = 0
    end
    object Edit4: TEdit
      Left = 88
      Top = 48
      Width = 70
      Height = 21
      TabOrder = 1
    end
    object Edit1: TEdit
      Left = 88
      Top = 75
      Width = 70
      Height = 21
      TabOrder = 2
    end
  end
  object GroupBox4: TGroupBox
    Left = 240
    Top = 151
    Width = 161
    Height = 89
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1080' '#1077#1083#1110#1087#1089#1072
    TabOrder = 4
    object Label6: TLabel
      Left = 14
      Top = 24
      Width = 52
      Height = 13
      Caption = #1057#1090#1086#1088#1086#1085#1072' 1'
    end
    object Label7: TLabel
      Left = 14
      Top = 51
      Width = 52
      Height = 13
      Caption = #1057#1090#1086#1088#1086#1085#1072' 2'
    end
    object Edit5: TEdit
      Left = 80
      Top = 21
      Width = 70
      Height = 21
      TabOrder = 0
    end
    object Edit6: TEdit
      Left = 80
      Top = 48
      Width = 70
      Height = 21
      TabOrder = 1
    end
  end
  object GroupBox5: TGroupBox
    Left = 240
    Top = 234
    Width = 161
    Height = 127
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1080' '#1076#1091#1075#1080
    TabOrder = 5
    object Label8: TLabel
      Left = 14
      Top = 24
      Width = 52
      Height = 13
      Caption = #1057#1090#1086#1088#1086#1085#1072' 1'
    end
    object Label9: TLabel
      Left = 14
      Top = 51
      Width = 52
      Height = 13
      Caption = #1057#1090#1086#1088#1086#1085#1072' 2'
    end
    object Label13: TLabel
      Left = 14
      Top = 78
      Width = 39
      Height = 13
      Caption = #1058#1086#1095#1082#1072' 1'
    end
    object Label14: TLabel
      Left = 14
      Top = 105
      Width = 39
      Height = 13
      Caption = #1058#1086#1095#1082#1072' 2'
    end
    object Edit7: TEdit
      Left = 80
      Top = 21
      Width = 70
      Height = 21
      TabOrder = 0
    end
    object Edit8: TEdit
      Left = 80
      Top = 48
      Width = 70
      Height = 21
      TabOrder = 1
    end
    object Edit10: TEdit
      Left = 80
      Top = 75
      Width = 70
      Height = 21
      TabOrder = 2
    end
    object Edit11: TEdit
      Left = 80
      Top = 102
      Width = 70
      Height = 21
      TabOrder = 3
    end
  end
  object GroupBox6: TGroupBox
    Left = 240
    Top = 363
    Width = 161
    Height = 67
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1080' '#1082#1074#1072#1076#1088#1072#1090#1072
    TabOrder = 6
    object Label10: TLabel
      Left = 14
      Top = 24
      Width = 49
      Height = 13
      Caption = #1044#1086#1074#1078#1080#1085#1072' '
    end
    object Label11: TLabel
      Left = 16
      Top = 37
      Width = 41
      Height = 13
      Caption = #1089#1090#1086#1088#1086#1085#1080
    end
    object Edit9: TEdit
      Left = 80
      Top = 29
      Width = 70
      Height = 21
      TabOrder = 0
    end
  end
  object Button1: TButton
    Left = 128
    Top = 328
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 7
  end
end
