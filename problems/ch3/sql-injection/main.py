import sqlite3
from flask import Flask, render_template, request

flag = "hitcon{test!}"
app = Flask(__name__)
DATABASE = './login.db'

@app.route('/')
def f():
    return render_template("login.html")
    
@app.route('/login', methods = ['POST', 'GET'])
def login():
    if request.method == 'POST':
        try:
            username = request.form['username']
            password = request.form['password']
        
            with sqlite3.connect(DATABASE) as con:
                cur = con.cursor()
                cur.execute(f"SELECT * FROM users WHERE username = '{username}' AND password = '{password}'")
                items = cur.fetchall()
                if items == []: msg = "Wrong username or password!"
                else : msg = f"Welcome {items[0][0]}! Here is your flag: {flag}!"
        except Exception as e:
            msg = e
      
        finally:
            return render_template("result.html", msg = msg)
    if request.method == 'GET':
        return render_template("login.html")

@app.route('/src')
def src():
    return render_template("./template.html", content=open(__file__).read()) 

if __name__ == '__main__':
      app.run(host='0.0.0.0', port=48763)
