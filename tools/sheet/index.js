'use strict';

const fs = require('fs');
const path = require('path');
const readline = require('readline');
const {google} = require('googleapis');

const OAUTH2_CRED_PATH = 'credentials.json'
const TOKEN_PATH = 'token.json';
const scopes = ['https://www.googleapis.com/auth/spreadsheets'];

const spreadsheetId = '1N_s39HpYevoJBNWT5LVSWbcblzgKNsamybsA8W2ynSU';
// each sheet only accept one range??
const ranges = ["'map01-outside-左上'!A1:C3", "'map02-outside-左下'!A1:C3"];


// create OAuth2 client id with type Desktop App from google cloud
const keyPath = path.join(__dirname, OAUTH2_CRED_PATH);
let keys = {redirect_uris: ['']};
if (fs.existsSync(keyPath)) {
  keys = require(keyPath).installed;
}

const oauth2Client = new google.auth.OAuth2(
  keys.client_id,
  keys.client_secret,
  keys.redirect_uris[0]
);

const tokenPath = path.join(__dirname, TOKEN_PATH);
if (fs.existsSync(tokenPath)) {
  const content = JSON.parse(fs.readFileSync(tokenPath));
  oauth2Client.setCredentials(content);
} else {
  getNewToken(oauth2Client);
}

function getNewToken(oauth2Client) {
  const authorizeUrl = oauth2Client.generateAuthUrl({
    access_type: 'offline',
    scope: scopes.join(' '),
  });

  console.log('Authorize this app by visiting this url:', authorizeUrl);

  const rl = readline.createInterface({
      input: process.stdin,
      output: process.stdout,
  });

  rl.question('Enter the code from that page here: ', (code) => {
      rl.close();
      oauth2Client.getToken(code, (err, token) => {
        if (err) return console.error('Error while trying to retrieve access token', err);
        oauth2Client.setCredentials(token);
        // Store the token to disk for later program executions
        fs.writeFile(TOKEN_PATH, JSON.stringify(token), (err) => {
          if (err) return console.error(err);
          console.log('Token stored to', TOKEN_PATH);
      });
    });
  });
}

function toHex(c) {
  var hex = c.toString(16).slice(0, 2);
  return hex.length == 1 ? "0" + hex : hex;
}

function rgbToHex(rgbColor) {
  const {red, green, blue} = rgbColor;
  var r = (red * 255);
  var g = (green * 255);
  var b = (blue * 255);
  var resultBuilder = ['#'];
  return '#' + toHex(r) + toHex(g) + toHex(b);
}

const app = google.sheets({version:'v4', auth: oauth2Client});

(async () => {
  const res = await app.spreadsheets.get({
    spreadsheetId,
    ranges,
    includeGridData: 'true',
  });
  const { sheets } = await res.data
  var mapData = {};
  sheets.map((sheet, index) => {
    const colorData = [];
    const { properties: {title} , data } = sheet;
    console.log(`${title} parsing...`);
    const {rowData} = data[0];
    rowData.map((row, index) => {
      row.values.map((cell, index) => {
        const {effectiveFormat: {backgroundColor}} = cell;
        const cellHexColor = rgbToHex(backgroundColor);
        colorData.push(cellHexColor);
      })
    })
    mapData[title] = {colorData, range: ranges[index]}
  });
  console.log(mapData)
})();


