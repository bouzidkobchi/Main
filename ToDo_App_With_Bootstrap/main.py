from flask import Flask , render_template , request , redirect , url_for , make_response
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///note.db'
app.config['SQLALCHEMY_TRACK_MODIFICATION'] = False
app.config['FLASK_APP'] = __file__

db = SQLAlchemy(app)
migrate = Migrate(app,db)

class note(db.Model) :
    id = db.Column(db.Integer , primary_key=True)
    name = db.Column(db.String(40)) 
    content = db.Column(db.String(370))
    status = db.Column(db.String(20))
    color = db.Column(db.String(10))

def add_note(name=None,content=None,status='not completed',note_color=None) :
    with app.app_context() :
        new_note = note(name=name,content=content,status=status,color=note_color)
        db.session.add(new_note)

        db.session.commit()

@app.route('/from_theme_<theme>_delete_note_<id>')
def delete_note(theme,id) :
    with app.app_context() :
        specific_note = note.query.get(id)
        db.session.delete(specific_note)
        db.session.commit()
    return redirect(url_for('theme',number=theme))

@app.route('/from_theme_<theme>_update_note_<id>',methods=['GET','POST'])
def update_note(theme,id) :
    if request.method == 'POST' : 
        name = request.form['name']
        content = request.form['content']
        note_color = request.form['note_color']

        with app.app_context() :
            specific_note = note.query.get(id)
            specific_note.name = name
            specific_note.content = content
            specific_note.color = note_color
            db.session.commit()
        return redirect(url_for('theme',number=theme))

    specific_note = note.query.get(id)

    return render_template('update_note.html',name=specific_note.name,context=specific_note.content,text_value=specific_note.content)

@app.route('/')
def home() :
    return redirect('theme2')

@app.route('/theme<int:number>',methods=['GET','POST'])
def theme(number) :
    if request.method == 'POST' :
        content = request.form['content']
        name = request.form['name']
        note_color = request.form['note_color']
        # don't save if name and content are empty :
        if content or name : add_note(name=name,content=content,note_color=note_color)

    notes = []

    rows = int(note.query.count()//3)+2
    for i in range(1,rows) :
        try :
            notes.append(note.query.paginate(page=i,per_page=3))
        except :
            continue
    yes = number == 2
    
    return render_template(f'theme.html',theme=number,notes=notes,colored=yes)

@app.route('/from_theme_<theme>_change_status_of_note_<id>',methods=['GET','POST'])
def change_status(theme,id) :
    with app.app_context() :
        updated = note.query.get(id)
        if updated.status == 'completed' : updated.status = 'not completed'
        else : updated.status = 'completed'
        db.session.commit()
    
    return redirect(url_for('theme',number=theme))

@app.errorhandler(404)
def pagenotfound(error) :
    return 'theme not found'


if __name__ == '__main__' :
    app.run(debug=False)


