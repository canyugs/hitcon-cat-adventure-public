# HITCON 2021：駭客貓歷險記（Hacker Cat Adventure)


## How to setup/run

Use the commands below to run the HITCON online service for HITCON 2021

```
basedir=`pwd`
git clone https://github.com/canyugs/hitcon-cat-adventure-public.git hitcon-cat-adventure
git clone https://github.com/canyugs/hitcon-online.git
cd "${basedir}/hitcon-cat-adventure"
git checkout origin/2021
cd "${basedir}/hitcon-online"
git checkout origin/2021
yarn install
./run-dev.sh ../hitcon-cat-adventure/run
```

## License

The assets under `tiled-maps` (NPCs, map tiles... etc) are copyright their respective authors.

Otherwise, this project is copyright hitcon-cat-adventure contributors and licensed under BSD 3-clause:
https://spdx.org/licenses/BSD-3-Clause.html

### Contributors

```
Allen Chou
CanYu
ccali66
Chi-Feng Tsai
David Su
fanlan1210
jim
John L Chen/Google
justinlin099
Lisa Wang
tiwb
zeze-zeze
```

## Structure and Usage

```
.
├── problems
│   ├── ch1
│   ├── ch2
│   ├── ch3
│   ├── ch4
│   ├── ch5
│   ├── ch6
│   └── other
├── run
│   ├── config
│   ├── map
│   │   └── watermark
│   ├── npc
│   └── terminal
```

problems
-----
Store problems for Hacker Cat Adventure. Each problem own it's directory and contain all things needed (e.g. dockerfile, document, or something) And to specific problem which chapter we used, please add directory to corresponding chapter directory (`ch1` === chapter1, `ch2` === chapter2...,etc). If problem not belong to any chapter like side quest use `other` instead.

run
-----
Store production configuration for HITCON Online.

