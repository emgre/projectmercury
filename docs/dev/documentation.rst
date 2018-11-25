Documentation
#############

The documentation is available at https://projectmercury.space.

Philosophy
==========

The documentation is written in the same repository as the code for the
following reasons:

#. Foster the documentation to be up to date with the code implementation
#. Provide documentation versioning matching the project releases
#. Provide continuous generation and publishing of the documentation

Technology
==========

Choice
------
The documentation is built using `Sphinx <http://www.sphinx-doc.org>`_ using
`reStructuredText <http://docutils.sourceforge.net/rst.html>`_ as a markup
language. The technology choice is based on the following arguments:

* Sphinx is a mature project with a great integration with `Read the Docs <https://readthedocs.org/>`_ [#readthedocssphinx]_.
* reStructuredText has a single standard definition and
  battle-tested parsers [#elibendersky]_.
* reStructuredText has standard extension mechanisms that can help avoid
  duplicate in code [#zverovich]_.
* Both technologies proved to be good choices in large-scale documentation, most
  notably for Python's documentation [#pythondoc]_ and the Linux Kernel
  documentation [#linuxkerneldoc]_.

Tutorials
---------

Here is a non-exhaustive list of resources for writing documentation in
reStructuredText tutorials:

* `An introduction to Sphinx and Read the Docs for Technical Writers <http://www.ericholscher.com/blog/2016/jul/1/sphinx-and-rtd-for-writers>`_, by Eric Holscher.
* `reStructuredText Primer <http://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html>`_
* `Writing content <https://mcss.mosra.cz/pelican/writing-content/>`_, by Vladimír Von­druš.
* `Read the Docs Sphinx Theme <https://sphinx-rtd-theme.readthedocs.io/en/latest/index.html>`_, for examples of the theme used.

Building
========

Requirements
------------

To build the documentation, the following programs are needed:

* `Python 3 <https://www.python.org/downloads/>`_
* `sphinx <https://pypi.org/project/Sphinx/>`_ :code:`pip install sphinx`
* `sphinx_rtd_theme <https://pypi.org/project/sphinx_rtd_theme/>`_ :code:`pip install sphinx_rtd_theme`

Build instructions
------------------

To documentation can be built by following these steps:

#. Open a terminal in the :code:`docs` directory
#. Run :code:`sphinx-build . build`

The documentation will available in :code:`docs/build` and can be opened with
any web browser. The default entry-point of the documentation is the
:code:`index.html` file.

Continuous integration
======================

`Read the Docs <https://readthedocs.org/>`_ is used to automatically build and
serve the different versions of the documentation. The result can be accessed at
https://projectmercury.space.

The documentation is built for every commit in the :code:`develop` branch.
Therefore, the :code:`latest` version of the documentation points to the latest
commit in the :code:`develop` branch.

Each of the releases is tagged with a semantic versioning number [#semver]_ and
will be made available as :code:`stable`.

References
==========

.. [#readthedocssphinx] `Getting Started with Sphinx <https://docs.readthedocs.io/en/latest/intro/getting-started-with-sphinx.html>`_
.. [#elibendersky] `reStructuredText vs. Markdown for technical documentation <https://eli.thegreenplace.net/2017/restructuredtext-vs-markdown-for-technical-documentation/#built-in-support-for-extensions>`_, Eli Bendersky.
.. [#zverovich] `reStructuredText vs Markdown for documentation <http://www.zverovich.net/2016/06/16/rst-vs-markdown.html>`_, Victor Zverovich.
.. [#pythondoc] `Documenting Python <https://devguide.python.org/documenting/>`_
.. [#linuxkerneldoc] `The Linux Kernel documentation <https://www.kernel.org/doc/html/latest/>`_
.. [#semver] `Semantic Versioning 2.0.0 <https://semver.org/spec/v2.0.0.html>`_
