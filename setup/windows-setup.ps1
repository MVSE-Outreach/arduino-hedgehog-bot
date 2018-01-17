$PSScriptRoot = Split-Path -Parent -Path $MyInvocation.MyCommand.Definition
$ESP8266_TOOLS_VERSION = "2.4.0"
$ESP8266_TOOLS_URL = "https://github.com/esp8266/Arduino/archive/2.4.0.zip"
$ESP8266_TOOLS_NAME = "esp8266-$ESP8266_TOOLS_VERSION"
$ESP8266_TOOLS_SRC = Join-Path -Path $PSScriptRoot -ChildPath "$ESP8266_TOOLS_NAME"
$ARDUINO_ROOT = "C:\Arduino"
$ESP8266_TOOLS_DEST = Join-Path -Path $ARDUINO_ROOT -ChildPath "hardware\esp8266com\esp8266"
$HHB_REPO_URL = "https://github.com/MVSE-Outreach/arduino-hedgehog-bot/archive/master.zip"
$HHB_SRC = Join-Path -Path $PSScriptRoot -ChildPath "arduino-hedgehog-bot-master"
$PYTHON = "C:\Python27\python.exe"

# Functions

Add-Type -AssemblyName System.IO.Compression.FileSystem
function Unzip {
    param([string]$zipFile, [string]$outPath)

    [System.IO.Compression.ZipFile]::ExtractToDirectory($zipFile, $outPath)
}

Function Download ($uri, $outFile) {
	If (! (Test-Path $outFile)) {
		Invoke-WebRequest -Uri $uri -OutFile $outFile
	}
}

# Main


If (! (Test-Path $ARDUINO_ROOT)) {
	Echo "Arduino not installed at $ARDUINO_ROOT, install and try again"
	Exit 1
}

If (! (Test-Path $ESP8266_TOOLS_SRC)) {
	Echo "ESP8266 Tools not found, downloading..."
	Download -Uri $ESP8266_TOOLS_URL -OutFile "$ESP8266_TOOLS_SRC.zip"
	Unzip "$ESP8266_TOOLS_SRC.zip" "$PSScriptRoot"
	Rename-Item "$PSScriptRoot\Arduino-$ESP8266_TOOLS_VERSION" $ESP8266_TOOLS_NAME

	# Download platform tools
	If (! (Test-Path $PYTHON)) {
		Echo "Python not found at $PYTHON, install and rerun the script"
		Exit 2
	}
	# Shitty python script needs to be executed from tools folder
	# as it uses relative paths
	Push-Location -Path "$ESP8266_TOOLS_SRC\tools"
	& $PYTHON "get.py"
	Pop-Location
}

If (! (Test-Path $ESP8266_TOOLS_DEST)) {
	Echo "Installing ESP8266 board tools"
	New-Item -Path $ESP8266_TOOLS_DEST -ItemType directory
	Copy-Item -Recurse $ESP8266_TOOLS_SRC/* $ESP8266_TOOLS_DEST
}


If (! (Test-Path $HHB_SRC)) {
	Echo "Hedgehog bot libraries not found, downloading..."
	Download -Uri $HHB_REPO_URL -OutFile "$HHB_SRC.zip"
	Unzip "$HHB_SRC.zip" "$PSScriptRoot"
}

Echo "Installing Hedgehog bot libraries"
Get-ChildItem $HHB_SRC/libraries/ | ForEach-Object {
	$Target = "$ARDUINO_ROOT/libraries/$($_.Name)"
	If (! (Test-Path $Target)) {
		Echo "Installing library $($_.Name)"
		Copy-Item -Recurse $_.FullName $Target
	}
}

Echo "All Done!"
