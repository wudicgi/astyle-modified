@echo off
set BAT_DIR=%~dp0
@echo on
"%BAT_DIR%AStyle_orig.exe" --options="%BAT_DIR%custom_coding_style.ini" --stdout="test_out_1_original_version.c" --stdin="test_in.c"
"%BAT_DIR%AStyle.exe" --options="%BAT_DIR%custom_coding_style.ini" --stdout="test_out_2_modified_version.c" --stdin="test_in.c"
@echo off
echo.
echo Completed
pause
