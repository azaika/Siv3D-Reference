﻿# インストール時のトラブルシューティング

### ◆ プロジェクトを作成すると「HRESULT からの例外」と表示されて作成に失敗する
#### 原因: お使いの Visual Studio に C++ の開発環境がインストールされていません。
Visual Studio Community はインストール時に選択しない限り C++ の開発環境がインストールされません。  
「新しいプロジェクト」の中に C++ の開発環境をインストールするためのメニューがあるので、画面の指示に従って C++ の開発環境をインストールしたのち、再度 Siv3D のプロジェクトを作成してください。

### ◆ プロジェクトを作ったのにソースコードが表示されない
#### 原因: 正常です。最初は何も表示されません。
Visual Studio のソリューション エクスプローラーから `Main.cpp` をクリックして開くとサンプルプログラムが開きます。

### ◆ プロジェクトを作ったのに Main.cpp が見つからない
#### 原因: ソリューション エクスプローラーが Visual Studio に表示されていません。
Visual Studio メニューの | 表示 | から | ソリューション エクスプローラー | をクリックするとソリューション エクスプローラーが現れます。その中の「ソースファイル」に `Main.cpp` があります。

![ソリューション エクスプローラー](resource/solutionexplorer.png "ソリューション エクスプローラー") 

### ◆ ビルドすると「Siv3D.hpp が見つからない」というエラーが出る
#### 原因: 環境変数の設定が間違っているか、Siv3D Package フォルダを移動・削除したためです。
Inc や Lib フォルダの親フォルダへのパスが、正しい環境変数に登録されているか確認してください。
