Dim message, sapi
Set wshShell = WScript.CreateObject( "WScript.Shell" )
Set sapi=CreateObject("sapi.spvoice")
sapi.Speak "Welcome, to A Pong Game"