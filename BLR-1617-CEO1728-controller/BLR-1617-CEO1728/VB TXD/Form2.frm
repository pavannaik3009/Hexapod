VERSION 5.00
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "shdocvw.dll"
Begin VB.Form Form2 
   ClientHeight    =   8595
   ClientLeft      =   165
   ClientTop       =   450
   ClientWidth     =   11700
   LinkTopic       =   "Form2"
   ScaleHeight     =   8595
   ScaleWidth      =   11700
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command3 
      Caption         =   "GET LOCATION"
      Height          =   615
      Left            =   240
      TabIndex        =   3
      Top             =   4560
      Width           =   1695
   End
   Begin VB.CommandButton Command2 
      Caption         =   "EXIT"
      Height          =   495
      Left            =   240
      TabIndex        =   2
      Top             =   6600
      Width           =   1695
   End
   Begin VB.CommandButton Command1 
      Caption         =   "BACK"
      Height          =   495
      Left            =   240
      TabIndex        =   1
      Top             =   5640
      Width           =   1695
   End
   Begin SHDocVwCtl.WebBrowser WebBrowser1 
      Height          =   10935
      Left            =   2640
      TabIndex        =   0
      Top             =   120
      Width           =   12615
      ExtentX         =   22251
      ExtentY         =   19288
      ViewMode        =   0
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   0   'False
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      NoWebView       =   0   'False
      HideFileNames   =   0   'False
      SingleClick     =   0   'False
      SingleSelection =   0   'False
      NoFolders       =   0   'False
      Transparent     =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   "http:///"
   End
End
Attribute VB_Name = "Form2"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Form1.Show
End Sub

Private Sub Command2_Click()
End
End Sub

Private Sub Command3_Click()
            queryAddress = "http://maps.google.com/maps?q="
            lat = Form1.Text1.Text + ","
            queryAddress = queryAddress & lat
            lon = Form1.Text2.Text
            queryAddress = queryAddress & lon
            WebBrowser1.Navigate queryAddress
End Sub

