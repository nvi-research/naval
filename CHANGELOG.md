# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

<!-- insertion marker -->
## [v0.3.1](https://github.com/nvi-research/naval/releases/tag/v0.3.1) - 2023-04-07

<small>[Compare with v0.3.0](https://github.com/nvi-research/naval/compare/v0.3.0...v0.3.1)</small>

### Docs

- update demo.gif ([0b024a0](https://github.com/nvi-research/naval/commit/0b024a090e7cb91d4b9114b9bf0b1ac2e86d5c91) by Vyacheslav Zhdanovskiy).
- add nice demos ([dd5feb7](https://github.com/nvi-research/naval/commit/dd5feb71da6218d83bd40c6a13dc2acac86de172) by Vyacheslav Zhdanovskiy).
- example and README ([9fe15e7](https://github.com/nvi-research/naval/commit/9fe15e78d1ca84beaf0b79b94c5c19b8b49f8e1b) by Vyacheslav Zhdanovskiy).
- doxygen docs ([a2844ac](https://github.com/nvi-research/naval/commit/a2844ac9b9dfc9f17745afcfc8c68a527edd8bfb) by Vyacheslav Zhdanovskiy).

## [v0.3.0](https://github.com/nvi-research/naval/releases/tag/v0.3.0) - 2022-12-30

<small>[Compare with v0.2.0](https://github.com/nvi-research/naval/compare/v0.2.0...v0.3.0)</small>

### Features

- increase protocol version ([d8bba19](https://github.com/nvi-research/naval/commit/d8bba19276652fb3e7abe74d59102c4d43efe58b) by Vyacheslav Zhdanovskiy).
- store timestamp in LogPacket ([0f490ba](https://github.com/nvi-research/naval/commit/0f490bac6a16556beee8e822f359e56894fbdf6b) by Vyacheslav Zhdanovskiy).
- add log_level to Tag ([16bda62](https://github.com/nvi-research/naval/commit/16bda621b41d26dec10fd418eb632e701798e2de) by Vyacheslav Zhdanovskiy).
- remove NAVAL_DEBUG and NAVAL_INFO macros, restore Debug and Info methods ([52be9c4](https://github.com/nvi-research/naval/commit/52be9c4cd6d247224af3ff0731faa294aa5291a0) by Vyacheslav Zhdanovskiy).

## [v0.2.0](https://github.com/nvi-research/naval/releases/tag/v0.2.0) - 2022-12-29

<small>[Compare with v0.1.0](https://github.com/nvi-research/naval/compare/v0.1.0...v0.2.0)</small>

### Bug Fixes

- allow to use NAVAL_* macros outside of naval namespace ([d286483](https://github.com/nvi-research/naval/commit/d286483ad352d674afbcfbeb39acc2a1e683e42f) by Vyacheslav Zhdanovskiy).

### Features

- increase protocol version ([3749d90](https://github.com/nvi-research/naval/commit/3749d90f777c23d2f9ed0ce49f237cfee3af194e) by Vyacheslav Zhdanovskiy).
- allow to track context in MessageMetadata ([085977a](https://github.com/nvi-research/naval/commit/085977abca782f8cc178ed4ee1a795571af336d7) by Vyacheslav Zhdanovskiy).
- new colors in palette ([8a0d8bc](https://github.com/nvi-research/naval/commit/8a0d8bc14f666f79cba55931dccce5234701a358) by Ilya Chaykin).

### Code Refactoring

- refactor serialization code ([66d9a9d](https://github.com/nvi-research/naval/commit/66d9a9dadeec5556f2d5d8c529ed579af1f84a5b) by Vyacheslav Zhdanovskiy).

## [v0.1.0](https://github.com/nvi-research/naval/releases/tag/v0.1.0) - 2022-12-19

<small>[Compare with v0.0.1](https://github.com/nvi-research/naval/compare/v0.0.1...v0.1.0)</small>

### Features

- add more colors to palette ([887862c](https://github.com/nvi-research/naval/commit/887862cf2b81ab1ee0109c6fd8702ce56eaf0c2b) by Vyacheslav Zhdanovskiy).
- upgrade protocol version ([895602e](https://github.com/nvi-research/naval/commit/895602e6981bc588fea148db50f39e54a03fbad6) by Vyacheslav Zhdanovskiy).
- add line_thickness to DrawProperties ([d02c6a0](https://github.com/nvi-research/naval/commit/d02c6a0ba59f93de658ef53b0b8d2c365350da00) by Vyacheslav Zhdanovskiy).
- add font_size to TagProperties ([ac4391b](https://github.com/nvi-research/naval/commit/ac4391b44ac57958c8ee12b497d67a3537d81b13) by Vyacheslav Zhdanovskiy).

## [v0.0.1](https://github.com/nvi-research/naval/releases/tag/v0.0.1) - 2022-12-15

<small>[Compare with first commit](https://github.com/nvi-research/naval/compare/476539231851f77c20c63867df92dbfe464c8686...v0.0.1)</small>

### Bug Fixes

- properly include sanitizers.cmake ([563dd3c](https://github.com/nvi-research/naval/commit/563dd3c7947b397d710bf88981977566a3e19257) by Vyacheslav Zhdanovskiy).
- lenna path in tests ([9841b67](https://github.com/nvi-research/naval/commit/9841b67908a9a3e95e0a7c3c2000923dcfeb7845) by Vyacheslav Zhdanovskiy).
- remove unused LogLevel ([678f420](https://github.com/nvi-research/naval/commit/678f420df638c234fbf10f7ceaffcf6bbef96132) by Vyacheslav Zhdanovskiy).

### Features

- write stream_url to log ([234853a](https://github.com/nvi-research/naval/commit/234853a93b2c51ed104193fd01d13c1e84aab677) by Vyacheslav Zhdanovskiy).
- write file signature and protocol version to stream file ([c9516da](https://github.com/nvi-research/naval/commit/c9516da4b2ef3b335109831e1386052badb26fc6) by Vyacheslav Zhdanovskiy).
- architecture simplification ([8809e79](https://github.com/nvi-research/naval/commit/8809e79968a5ebbcadddbbe78437f95a63e7af46) by Vyacheslav Zhdanovskiy).
- basic working version ([e13cdd0](https://github.com/nvi-research/naval/commit/e13cdd0274ec2c6805b249d6675fee9f4858d4fd) by Vyacheslav Zhdanovskiy).

### Code Refactoring

- rename WriteFrame to WritePacket ([e7d938a](https://github.com/nvi-research/naval/commit/e7d938a500e2f5a2e38f6d0b92886d2c84075688) by Vyacheslav Zhdanovskiy).
- newlines in .clang-format and .gitignore ([28c93eb](https://github.com/nvi-research/naval/commit/28c93ebce2c15d68d8936490cda9401f472cd6f8) by Vyacheslav Zhdanovskiy).

### Docs

- add CHANGELOG.md ([c60809e](https://github.com/nvi-research/naval/commit/c60809e2c9e63de001af530b98726d5f5ed567c6) by Vyacheslav Zhdanovskiy).

