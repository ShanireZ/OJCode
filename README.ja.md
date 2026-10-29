# OJCode

[![License: GPL-3.0](https://img.shields.io/badge/license-GPL--3.0-blue.svg?style=flat-square)](LICENSE)
![Type: solution archive](https://img.shields.io/badge/type-solution%20archive-success.svg?style=flat-square)
![C++14](https://img.shields.io/badge/C%2B%2B-14-00599C.svg?style=flat-square&logo=cplusplus&logoColor=white)
![Primary OJ: Luogu](https://img.shields.io/badge/primary%20OJ-Luogu-blue.svg?style=flat-square)

[English](README.md) | [简体中文](README.zh-CN.md) | [繁體中文(TW)](README.zh-TW.md) | [日本語](README.ja.md)

OJCode は主に Luogu のオンラインジャッジ問題を扱う個人の解答コード集です。各 `.cpp` ファイルは、一問に対応する単独でコンパイル可能な解答です。

## 対象のオンラインジャッジ

- [Luogu](https://www.luogu.com.cn/)
- [CodeForces](https://codeforces.com/)
- [LibreOJ](https://loj.ac/)
- [PTA](https://pintia.cn/)
- [SPOJ](https://www.spoj.com/)
- [AtCoder](https://atcoder.jp/)
- [UVaOJ](https://onlinejudge.org/)

## 構成と使い方

- `Luogu/`、`CodeForces/`、`LOJ/`、`PAT/`、`SP UVA AT/` にジャッジ別の解答を収録しています。通常、ファイル名には問題番号が含まれます。
- 共通のビルドシステムやテスト基盤はありません。必要なファイルを C++14 コンパイラーで個別にビルドして実行してください。例：`g++ -std=c++14 path/to/solution.cpp -o solution`。
- アルゴリズムのタグは順次追加しています。タグのない古いファイルも収録対象です。収録されていることは、現在のジャッジ環境での正答判定を保証しません。

## 貢献

問題報告や修正案にはジャッジ名と問題番号を記載してください。解答を変更する際はアルゴリズムのタグを補い、利用できるサンプル入出力を確認してください。

## ライセンス

[GNU General Public License v3.0](LICENSE) に基づいて配布します。
