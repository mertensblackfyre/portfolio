let
  pkgs = import <nixpkgs> {};
in
  pkgs.mkShell {
    packages = [
      #pkgs.leptonica
      pkgs.go
      pkgs.air
      pkgs.templ
    ];
  }
