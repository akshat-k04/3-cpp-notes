# parent.ps1
Write-Host "Parent process started"
Start-Process -NoNewWindow -FilePath powershell.exe -ArgumentList ".\child.ps1"
Write-Host "Parent process will exit now"
