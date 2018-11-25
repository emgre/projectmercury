# Configuration file for the Sphinx documentation builder.
#
# For a full list of options, see the documentation:
# http://www.sphinx-doc.org/en/master/config

# General information
project = 'Project Mercury'
copyright = u'2018, Émile Grégoire'
author = u'Émile Grégoire'
language = 'en'

version = '6.0'
release = '6.0.0'

# General settings
master_doc = 'index'
source_suffix = '.rst'
templates_path = ['_templates']
exclude_patterns = []
extensions = [
]

# HTML Settings
html_theme = 'sphinx_rtd_theme'
html_theme_options = {}
html_static_path = ['_static']
pygments_style = None
