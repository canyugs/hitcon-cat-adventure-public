# Google Sheet to Tiled


## Requirements

1. create OAuth2 Client Id, follow [instruction](https://googleapis.dev/nodejs/googleapis/latest/sheets/index.html#oauth2-client)

2. config `spreadsheetId` and `ranges` in index.js

3. run cmd

```sh
# cmd
yarn
node .

# output with colorData
map01-outside-左上 parsing...
map02-outside-左下 parsing...
{
  'map01-outside-左上': {
    colorData: [
      '#ffffff', '#ffffff',
      '#ffffff', '#ffffff',
      '#8ea9db', '#8ea9db',
      '#ffffff', '#8ea9db',
      '#8ea9db'
    ],
    range: "'map01-outside-左上'!A1:C3"
  },
  'map02-outside-左下': {
    colorData: [
      '#ffffff', '#8ea9db',
      '#8ea9db', '#8ea9db',
      '#8ea9db', '#8ea9db',
      '#8ea9db', '#8ea9db',
      '#8ea9db'
    ],
    range: "'map02-outside-左下'!A1:C3"
  }
}
```
