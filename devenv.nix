{ pkgs, lib, config, inputs, ... }:

{
  # https://devenv.sh/packages/
  packages = with pkgs; [
    conan
    libGLU
    
    xorg.libX11
    xorg.libfontenc
    xorg.libICE
    xorg.libSM
    xorg.libXau
    xorg.libXaw
    xorg.libXcomposite
    xorg.libXcursor
    xorg.libXdamage
    xorg.libXdmcp
    xorg.libXext
    xorg.libXi
    xorg.libXinerama
    xorg.libxkbfile
    xorg.libXpm
    xorg.libXrandr
    xorg.libXres
    xorg.libXScrnSaver
    xorg.libXtst
    xorg.libXv
    xorg.libXxf86vm
    xorg.libxcb
    xorg.xcbutilwm
    xorg.xcbutilimage
    xorg.xcbutilkeysyms
    xorg.xcbutilrenderutil
    xorg.xcbutil
    xorg.xcbproto
    xorg.xcbutilerrors
    xorg.xcbutilcursor
    
    libuuid
    ];

  # https://devenv.sh/languages/
  # languages.nix.enable = true;
  languages.cplusplus.enable = true;

}
