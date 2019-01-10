VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "mscomm32.ocx"
Begin VB.Form Form1 
   BackColor       =   &H00000000&
   Caption         =   "Form1"
   ClientHeight    =   10935
   ClientLeft      =   60
   ClientTop       =   255
   ClientWidth     =   15120
   LinkTopic       =   "Form1"
   ScaleHeight     =   10935
   ScaleWidth      =   15120
   StartUpPosition =   2  'CenterScreen
   Begin VB.CommandButton Command8 
      Caption         =   "STOP"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   9240
      TabIndex        =   22
      Top             =   4560
      Width           =   1335
   End
   Begin VB.CommandButton Command7 
      Caption         =   "RIGHT"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   11280
      TabIndex        =   21
      Top             =   4560
      Width           =   1335
   End
   Begin VB.CommandButton Command5 
      Caption         =   "LEFT"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   7200
      TabIndex        =   20
      Top             =   4560
      Width           =   1335
   End
   Begin VB.CommandButton Command3 
      Caption         =   "FORWARD"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   9240
      TabIndex        =   19
      Top             =   2880
      Width           =   1335
   End
   Begin VB.CommandButton Command6 
      BackColor       =   &H00FFC0C0&
      Caption         =   "REVERSE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   9240
      TabIndex        =   17
      Top             =   6120
      Width           =   1335
   End
   Begin VB.TextBox Text6 
      Height          =   615
      Left            =   2520
      TabIndex        =   16
      Top             =   6360
      Width           =   1215
   End
   Begin VB.CommandButton Command4 
      BackColor       =   &H00FFC0C0&
      Caption         =   "CLEAR"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   8280
      Style           =   1  'Graphical
      TabIndex        =   14
      Top             =   9720
      Width           =   1575
   End
   Begin VB.TextBox Text13 
      Height          =   735
      Left            =   3840
      TabIndex        =   13
      Top             =   1200
      Width           =   1935
   End
   Begin VB.TextBox Text12 
      Height          =   615
      Left            =   960
      TabIndex        =   12
      Top             =   1200
      Width           =   1815
   End
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   240
      Top             =   6120
   End
   Begin VB.TextBox Text3 
      Height          =   1095
      Left            =   1440
      TabIndex        =   7
      Top             =   9480
      Width           =   4695
   End
   Begin VB.Frame Frame2 
      BackColor       =   &H00FFC0C0&
      Caption         =   "SETTINGS"
      ForeColor       =   &H00000040&
      Height          =   2295
      Left            =   1440
      TabIndex        =   0
      Top             =   3240
      Width           =   4695
      Begin VB.CommandButton Command2 
         BackColor       =   &H8000000E&
         Caption         =   "EXIT"
         Height          =   495
         Left            =   840
         Style           =   1  'Graphical
         TabIndex        =   8
         Top             =   1560
         Width           =   1335
      End
      Begin VB.CommandButton Command1 
         BackColor       =   &H8000000E&
         Caption         =   "SET"
         Height          =   495
         Left            =   2880
         Style           =   1  'Graphical
         TabIndex        =   5
         Top             =   1560
         Width           =   1215
      End
      Begin VB.TextBox Text5 
         Enabled         =   0   'False
         Height          =   285
         Left            =   2880
         TabIndex        =   4
         Text            =   "9600"
         Top             =   960
         Width           =   1215
      End
      Begin VB.TextBox Text4 
         Height          =   285
         Left            =   2880
         TabIndex        =   3
         Top             =   480
         Width           =   1215
      End
      Begin VB.Label Label5 
         BackColor       =   &H00FFC0C0&
         Caption         =   "BAUD RATE:"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   -1  'True
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00000040&
         Height          =   375
         Left            =   360
         TabIndex        =   2
         Top             =   960
         Width           =   2295
      End
      Begin VB.Label Label4 
         BackColor       =   &H00FFC0C0&
         Caption         =   "COM PORT:"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   12
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   -1  'True
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00000040&
         Height          =   375
         Left            =   360
         TabIndex        =   1
         Top             =   480
         Width           =   2055
      End
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   240
      Top             =   7200
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.Label Label6 
      BackColor       =   &H00FFC0C0&
      Caption         =   "BOMB DETECTED"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   10200
      TabIndex        =   24
      Top             =   7440
      Width           =   3375
   End
   Begin VB.Label Label1 
      BackColor       =   &H00FFC0C0&
      Caption         =   "FIRE DETECTED"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   6720
      TabIndex        =   23
      Top             =   7440
      Width           =   2655
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      BackColor       =   &H00FFC0C0&
      Caption         =   "ROBOT CONTROL"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   15
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   7920
      TabIndex        =   18
      Top             =   1800
      Width           =   3975
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackColor       =   &H00FFC0C0&
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   7695
      Left            =   6480
      TabIndex        =   15
      Top             =   1080
      Width           =   7815
   End
   Begin VB.Label Label16 
      BackColor       =   &H00000000&
      Caption         =   "TIME"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFF00&
      Height          =   615
      Left            =   2880
      TabIndex        =   11
      Top             =   1320
      Width           =   1095
   End
   Begin VB.Label Label14 
      BackColor       =   &H00000000&
      Caption         =   "DATE"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFF00&
      Height          =   855
      Left            =   0
      TabIndex        =   10
      Top             =   1200
      Width           =   1215
   End
   Begin VB.Label Label13 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackColor       =   &H00000000&
      Caption         =   "AUTOMATIC IRRIGATION SYSTEM"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFF80&
      Height          =   435
      Left            =   -3600
      TabIndex        =   9
      Top             =   360
      Width           =   22215
      WordWrap        =   -1  'True
   End
   Begin VB.Label Label8 
      Alignment       =   2  'Center
      BackColor       =   &H80000012&
      ForeColor       =   &H8000000E&
      Height          =   495
      Left            =   7200
      TabIndex        =   6
      Top             =   1440
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public db As New ADODB.Connection
Public rs1 As New ADODB.Recordset
Dim queryAddress As String
Dim lat, lat1 As Integer
Dim lon, lon1 As Integer
Dim lo, la, balance As Integer
Dim i, j, k, l As Integer


Private Sub Command3_Click()
MSComm1.Output = "*1" + vbCrLf
End Sub

Private Sub Command4_Click()  'For Clear
Text3.Text = ""
Text6.Text = ""
End Sub
Private Sub Command1_Click()
On Error Resume Next
With MSComm1
    .CommPort = Val(Text4.Text)
    .Handshaking = comNone          ' For select com port
    .RThreshold = 1
    .SThreshold = 8
    .Settings = "9600,n,8,1"        'For GSM Modem Initialization
    .PortOpen = True
    balance = 100
    Label1.Visible = False
    Label6.Visible = False
End With
End Sub

Private Sub Command2_Click()  'For Exit
End
End Sub


Private Sub Command5_Click()
MSComm1.Output = "*3" + vbCrLf
End Sub

Private Sub Command6_Click()
MSComm1.Output = "*2" + vbCrLf
End Sub


Private Sub Command7_Click()
MSComm1.Output = "*4" + vbCrLf
End Sub

Private Sub Command8_Click()
MSComm1.Output = "*5" + vbCrLf
End Sub

Private Sub MSComm1_OnComm()
    Dim databuf As String
    Select Case comEvReceive
    Case comEvReceive
    
    databuf = MSComm1.Input
    Text3.Text = Text3.Text + databuf
    If Len(Text3.Text) = 2 And Mid(Text3.Text, 1, 2) = "*1" Then
        Label1.Visible = True
    ElseIf Len(Text3.Text) = 2 And Mid(Text3.Text, 1, 2) = "*2" Then
        Label1.Visible = False
        
        Text3.Text = ""
    End If
    
    If Len(Text3.Text) = 2 And Mid(Text3.Text, 1, 2) = "*3" Then
        Label6.Visible = True
    ElseIf Len(Text3.Text) = 2 And Mid(Text3.Text, 1, 2) = "*4" Then
        Label6.Visible = False
        
        Text3.Text = ""
    End If
    
    End Select
        
End Sub


Private Sub Timer1_Timer()
Text12.Text = Date           ' To View Date
Text13.Text = Time           ' To View Time
End Sub

