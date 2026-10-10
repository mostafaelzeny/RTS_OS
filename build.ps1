param(
    [string]$Target = "all"
)

$toolchainPath = "C:\ST\STM32CubeIDE_1.13.1\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.11.3.rel1.win32_1.1.0.202305231506\tools\bin"
$makePath = "C:\ST\STM32CubeIDE_1.13.1\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.make.win32_2.1.0.202305091550\tools\bin"

$env:PATH = "$toolchainPath;$makePath;" + $env:PATH

Write-Host "==> Running make in Debug/ ($Target)..." -ForegroundColor Cyan
& "$makePath\make.exe" -C Debug $Target
