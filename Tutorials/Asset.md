﻿# 20. アセット管理

## アセット管理の基本
Siv3D は `Texture` や `Sound`, `Font`, `GUI` などのアセットのハンドルに名前をつけ、名前を通してプログラムのどこからでもアクセスできる「アセット管理」の機能を提供しています。  
プログラムでアセット管理を扱う手順は以下の通りです。

1. アセットの「登録 (Register)」
2. アセットの「プリロード (Preload)」（省略可能）
3. アセットの「使用」
4. アセットの「リリース (Release)」（省略可能）
5. アセットの「登録解除 (Unregister)」（省略可能）

## 登録
アセットをエンジンに登録します。  
アセットの種類（テクスチャであるか、サウンドであるかなど）を関数で指定し、アセットに一意の名前をつけ、ファイル名やプロパティなどの情報を登録します。  
この時点ではアセットデータは構築されないので、メモリの消費量が増えることはありません。

## プリロード
アセットデータを実際にロードします。  
アセットの名前を指定すると、エンジンが該当アセットの登録時に与えられたファイル名やプロパティに従ってメモリにアセットデータを構築します。  
指定されたアセットがすでにロードされている場合は何もしません。

## 使用
アセットの名前を指定して、Texture 型や Sound 型のアセットハンドルを取得します。  
このハンドルを使って、従来のアセットハンドルのように draw() したり、play() したりすることができます。  
指定されたアセットが登録されていなかった場合は Null オブジェクトを返し、プリロードされていなかった場合はロードを実行してから結果のハンドルを返します。

## リリース
アセットデータをメモリ上から解放します。  
リリース後もアセットの登録情報は残っているため、再度プリロードしたり、使用したりすることができます。  
一度ロードしたアセットをこの先しばらく使わず、メモリ消費を抑えたい場合にアセットのリリースをしましょう。  

## 登録解除
アセットの登録情報と名前をアセット管理から削除します。  
該当アセットがリリースされていなかった場合はリリースします。  
アプリケーション終了時にはすべてのアセットが自動でリリース、登録解除されるため、アセットの登録解除を明示的に行う必要はありません。  

## Texture アセットのサンプル

```cpp
# include <Siv3D.hpp>

void Draw()
{
	TextureAsset(L"picture").draw();
}

void Main()
{
	TextureAsset::Register(L"picture", L"Example/Windmill.png");

	while (System::Update())
	{
		Draw();
	}
}
```

## Sound アセットのサンプル

```cpp
# include <Siv3D.hpp>

void Play()
{
	SoundAsset(L"music").play();
}

void Main()
{
	SoundAsset::Register(L"music", L"Example/風の丘.mp3");

	Play();

	while (System::Update())
	{

	}
}
```

## Font アセットのサンプル

```cpp
# include <Siv3D.hpp>

void Draw()
{
	FontAsset(L"font")(L"Hello, Siv3D!").draw();
}

void Main()
{
	FontAsset::Register(L"font", 35, Typeface::Black);

	while (System::Update())
	{
		Draw();
	}
}
```

[← 前の章へ戻る](GUI.md)　|　[- 目次 -](Index.md)　|　[次の章へ進む →](Image.md)