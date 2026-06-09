# Flask Notes

## 1. Introduction to Flask
- Flask is a lightweight Python web framework for building web applications.
- It is a microframework: no built-in ORM, no form validation library, no admin panel.
- Flask is based on Werkzeug (WSGI utilities) and Jinja2 (templating engine).
- Ideal for learning web development, building APIs, small web apps, or prototypes.

### Flask features
- Routing for URLs.
- Request and response handling.
- Template rendering with Jinja.
- Session and cookie support.
- Extensions for databases, forms, authentication, etc.

## 2. Flask Basics
### Starting a Flask app
- Install Flask: `pip install flask`.
- Create `app.py` with:
  ```python
  from flask import Flask

  app = Flask(__name__)

  @app.route('/')
  def index():
      return 'Hello, Flask!'

  if __name__ == '__main__':
      app.run(debug=True)
  ```
- `app.route()` defines a route and HTTP method defaults to GET.
- `app.run(debug=True)` starts the development server and enables debug mode.

### Flask application structure
- `app = Flask(__name__)` initializes the application.
- `__name__` helps Flask locate static files and templates.
- Common folders:
  - `templates/` for HTML templates.
  - `static/` for CSS, JavaScript, images.

## 3. Routing and URL Building
- Use `@app.route('/path')` for URL routing.
- Dynamic routes with variables:
  ```python
  @app.route('/user/<username>')
  def profile(username):
      return f'User: {username}'
  ```
- Convert types: `<int:id>`, `<float:value>`, `<path:subpath>`.
- `url_for('function_name', arg=value)` builds URLs dynamically.

## 4. Jinja and Templates
- Jinja is Flask's templating engine.
- Templates live in `templates/`.
- Basic template example:
  ```html
  <!doctype html>
  <html>
    <head><title>{{ title }}</title></head>
    <body>
      <h1>{{ heading }}</h1>
      <p>{{ message }}</p>
    </body>
  </html>
  ```
- In Flask view:
  ```python
  from flask import render_template

  @app.route('/')
  def home():
      return render_template('index.html', title='Home', heading='Welcome', message='Hello!')
  ```

### Jinja syntax
- Variables: `{{ variable }}`.
- Control structures:
  ```jinja
  {% if user %}
    Hello, {{ user }}!
  {% else %}
    Hello, guest!
  {% endif %}

  {% for item in list %}
    <li>{{ item }}</li>
  {% endfor %}
  ```
- Filters modify output: `{{ name|upper }}`, `{{ value|default('N/A') }}`.
- Template inheritance:
  - Define base template with blocks.
  - Child templates extend base and override blocks.

## 5. Templates and Static Files
- Templates are HTML files with embedded Jinja.
- Static assets served from `static/`.
- In templates use `url_for('static', filename='style.css')`.
- Example layout:
  - `templates/base.html`
  - `templates/index.html`
  - `static/style.css`

## 6. Request Methods
- HTTP methods: GET, POST, PUT, DELETE, PATCH.
- Define allowed methods in route:
  ```python
  @app.route('/submit', methods=['GET', 'POST'])
  def submit():
      if request.method == 'POST':
          data = request.form.get('name')
          return f'Received {data}'
      return render_template('form.html')
  ```
- Access request data:
  - `request.args` for query string parameters.
  - `request.form` for form data.
  - `request.json` for JSON bodies.
  - `request.files` for uploaded files.
- Use `redirect(url_for('route'))` to redirect after POST.
- `flash()` and `get_flashed_messages()` provide user feedback.

## 7. Form Handling
- Use HTML forms inside templates.
- Example form:
  ```html
  <form action="{{ url_for('submit') }}" method="post">
    <input name="username" type="text">
    <button type="submit">Send</button>
  </form>
  ```
- Use `request.form['username']` or `request.form.get('username')`.

## 8. Frosh IMS
- Frosh IMS is a common CS50 Flask problem set exercise.
- It typically manages student registration or inventory with SQLite.
- Core concepts:
  - Display data from a database.
  - Add, update, and remove records.
  - Use forms to submit search queries.
  - Show results in templates.
- Typical workflow:
  1. Connect to SQLite.
  2. Define routes for index, register, search.
  3. Render templates for input and output.

## 9. SQLite and Python
- SQLite is a file-based SQL database.
- Use Python's built-in `sqlite3` module.
- Example connection:
  ```python
  import sqlite3
  from flask import g

  DATABASE = 'frosh.db'

  def get_db():
      if 'db' not in g:
          g.db = sqlite3.connect(DATABASE)
          g.db.row_factory = sqlite3.Row
      return g.db

  @app.teardown_appcontext
  def close_db(exception):
      db = g.pop('db', None)
      if db is not None:
          db.close()
  ```
- Common queries:
  - `db.execute('SELECT * FROM students WHERE name = ?', (name,)).fetchone()`
  - `db.execute('INSERT INTO students (name, house) VALUES (?, ?)', (name, house))`
  - `db.commit()` after writes.
- Use `row_factory = sqlite3.Row` for dict-like row access.

## 10. Cookies and Sessions
- Cookies store small values in the browser.
- Sessions store data between requests on the server side, but by default Flask keeps the session data in a secure cookie.
- Set `app.secret_key` for session security.
- Example:
  ```python
  from flask import session

  app.secret_key = 'replace-with-secret-key'

  @app.route('/login', methods=['POST'])
  def login():
      session['username'] = request.form['username']
      return redirect(url_for('dashboard'))

  @app.route('/dashboard')
  def dashboard():
      if 'username' not in session:
          return redirect(url_for('login'))
      return f'Hello, {session["username"]}!'
  ```
- Clear session with `session.clear()`.
- Cookies can also be set manually with response objects:
  ```python
  resp = make_response(render_template('index.html'))
  resp.set_cookie('name', 'value')
  return resp
  ```

## 11. Shopping Cart Example
- A shopping cart stores selected items for a user.
- Use sessions to keep cart state between requests.
- Example logic:
  ```python
  @app.route('/add/<int:item_id>')
  def add(item_id):
      cart = session.get('cart', [])
      cart.append(item_id)
      session['cart'] = cart
      return redirect(url_for('cart'))

  @app.route('/cart')
  def cart():
      items = session.get('cart', [])
      return render_template('cart.html', items=items)
  ```
- Show cart contents in a template with item names and totals.
- Remove items by updating session data.

## 12. Shows Application
- A shows app displays television shows, movies, or events.
- Common features:
  - List shows using database query.
  - Search shows by title or category.
  - Add and edit show details.
  - Display show pages with images and description.
- Example route structure:
  - `/shows` — list all shows.
  - `/shows/<int:id>` — show details.
  - `/search` — query shows.
  - `/add-show` — form to add new show.

## 13. APIs with Flask
- API stands for Application Programming Interface.
- Use Flask to build RESTful APIs.
- Return JSON responses with `jsonify()`:
  ```python
  from flask import jsonify

  @app.route('/api/shows')
  def api_shows():
      shows = [{'id': 1, 'title': 'Example'}]
      return jsonify(shows)
  ```
- Accept JSON input:
  ```python
  @app.route('/api/shows', methods=['POST'])
  def create_show():
      data = request.get_json()
      title = data.get('title')
      ```
- HTTP status codes: `return jsonify(data), 201`.
- Use URL parameters and query strings for filtering.

## 14. Additional Related Topics
### Error Handling
- Custom error pages:
  ```python
  @app.errorhandler(404)
  def page_not_found(e):
      return render_template('404.html'), 404
  ```
- Handle exceptions with `@app.errorhandler(500)`.

### Blueprints
- Blueprints organize large applications.
- Example:
  ```python
  from flask import Blueprint
  auth = Blueprint('auth', __name__)
  ```
- Register blueprints with `app.register_blueprint(auth)`.

### Configuration
- Keep secrets and settings separate.
- Use `app.config['SECRET_KEY']` and load from environment variables.
- Support multiple environments: development, testing, production.

### Database Migrations
- Use Flask-Migrate and Alembic for schema changes.
- Manage database updates without dropping data.

### Authentication and Authorization
- Flask-Login for user sessions and login state.
- Protect pages with login required decorators.
- Hash passwords using `werkzeug.security.generate_password_hash()`.

### RESTful Design
- Use resource-based URLs.
- Match HTTP methods to actions:
  - GET to read
  - POST to create
  - PUT/PATCH to update
  - DELETE to remove
- Keep APIs stateless.

### Deployment
- Use a production WSGI server like Gunicorn or uWSGI.
- Deploy on platforms such as Heroku, PythonAnywhere, AWS, or DigitalOcean.
- Set `DEBUG = False` in production.

### Security Best Practices
- Validate user input.
- Protect against CSRF, XSS, and SQL injection.
- Use HTTPS and secure cookies.
- Keep secret keys secret.

## 15. Summary
- Flask is a great starting point for web development.
- Key concepts: routes, templates, requests, forms, databases, sessions, and APIs.
- Build apps incrementally: start with routes and templates, then add forms, data persistence, and sessions.
- Use SQLite for simple storage, and move to larger databases as needed.
- Keep code organized and secure for real deployments.

