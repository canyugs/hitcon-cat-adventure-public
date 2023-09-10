# must be run as root, as it requires access to the enter button
import keyboard
import requests
import json
from time import sleep

def call_enter_api(host="www.hitcon2022.online", port=443, apiKey="eKpvyrwezXArTj47UWvvrn7G8xADMKHB", api="escape-game/openDoor"):
    headers = {'Content-Type': 'application/json'}
    data = {"apiKey": apiKey, "args": [3000]}
    data = json.dumps(data)
    response = requests.post(
                    f'https://{host}:{port}/e2s/{api}',
                    headers=headers,
                    data=data
               )
    print(response)

def main():
    while True:
        keyboard.wait("enter")
        call_enter_api()

main()
