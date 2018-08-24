.. include:: ../links.txt
.. include:: ../roles.txt

.. _soft_req:

.. contents:: Table of Contents
   :local:
   :depth: 1
   :backlinks: top

.. note::

    In this section, we will briefly introduce the software skill suggestions
    for taking this course. We will provide useful links for you to further
    train yourself.

.. _soft_req_docker:

Using Our `Docker`_ Container
=============================

Why not take the advantage of cloud computing for teaching? The answer we come
up with is `Docker`_ contains, which allow you run a collection of software
packages (including OS) regardless your host machine systems. This class is
cluster-free, i.e. you don't need to worry about dealing with our clusters and
running everything through command lines.

First, read the description of our `Docker`_ container, i.e.
`AMS 562 container`_. Once you have installed `Docker`_ and `Python`_,
download these two scripts that will ease the process for using our container.

- Desktop driver: `ams562_desktop.py <https://raw.githubusercontent.com/compdatasci/ams562-desktop/master/ams562_desktop.py>`_
- Jupyter driver: `ams562_jupyter,py <https://raw.githubusercontent.com/compdatasci/ams562-desktop/master/ams562_jupyter.py>`_

**For the first time**, open a terminal/console/powershell session:

.. code-block:: console

    $ python ams562_desktop

This will automatically pull the container and create the desktop environment
in your default web browser. To see all options:

.. code-block:: console

    $ python ams562_desktop -h
    usage: ams562_desktop.py [-h] [-i IMAGE] [-t TAG] [-v VOLUME] [-w WORKDIR]
                         [-p] [-r] [-c] [-d] [-s SIZE] [-n] [-N] [-V] [-q]
                         [-A ARGS]

    Launch a Docker image with Ubuntu and LXDE window manager, and automatically
    open up the URL in the default web browser. It also sets up port forwarding
    for ssh.

    optional arguments:
    -h, --help            show this help message and exit
    -i IMAGE, --image IMAGE
                          The Docker image to use. The default is
                          ams562/desktop.
    -t TAG, --tag TAG     Tag of the image. The default is latest. If the image
                          already has a tag, its tag prevails.
    -v VOLUME, --volume VOLUME
                          A data volume to be mounted at ~/" + projdir + ". The
                          default is ams562_project.
    -w WORKDIR, --workdir WORKDIR
                          The starting work directory in container. The default
                          is ~/project.
    -p, --pull            Pull the latest Docker image. The default is not to
                          pull.
    -r, --reset           Reset configurations to default.
    -c, --clear           Clear the project data volume (please use with
                          caution).
    -d, --detach          Run in background and print container id
    -s SIZE, --size SIZE  Size of the screen. The default is to use the current
                          screen size.
    -n, --no-browser      Do not start web browser
    -N, --nvidia          Mount the Nvidia card for GPU computation. (Linux
                          only, experimental, sudo required).
    -V, --verbose         Enable verbose mode and print debug info to stderr.
    -q, --quiet           Disable screen output (some Docker output cannot be
                          disabled).
    -A ARGS, --args ARGS  Additional arguments for the "docker run" command.
                          Useful for specifying additional resources or
                          environment variables.

.. tip::

    Always run with :code:`$ python ams562_desktop -p` to get the newest
    container since our `Docker`_ image is automatically rebuilt weekly.

The following directories are mirrored to your local machine:

.. table::
    :align: center

    ============================= ==========================
    Docker directories            Host directories
    ============================= ==========================
    :code:`$DOCKER_HOME/shared`   Current working directory
    :code:`$DOCKER_HOME/project`  Data volume
    :code:`$DOCKER_HOME/.ssh`     :code:`$HOME/.ssh`
    :code:`$DOCKER_HOME/.config`  :code:`$HOME/.config`
    ============================= ==========================

The most commonly used is the ``shared`` directory, which allows you rapidly
exchange data between the container and your host machine.

.. warning::

    Except the above four directories, any changes to the container will not
    be persistent.

.. _soft_req_git:

Using `Git`_ with SSH Keys
==========================

.. contents::
   :local:
   :backlinks: top

What is Git?
------------

Version control system definitely helps your work. I found this
`online material <http://swcarpentry.github.io/git-novice/>`_ is interesting
and helpful, please take a look at it.

`SmartGit`_ is a nice GUI system for `Git`_.

.. tip::

    You may also find using `Git`_ in `Visual Studio Code`_ is handy, see
    :ref:`here <soft_req_vscode_git>`.

Set up your private repository on `Bitbucket`_
----------------------------------------------

We will use one of the popular online git network, `Bitbucket`_, to collect
your homework assignments. Register an account with your **SBU** email
address, then create a **private** repository following this
`description <https://confluence.atlassian.com/bitbucket/create-a-git-repository-759857290.html>`_.

Name your repository with ``ams562_<your name>``. And initialize your
repository with a ``README.md`` that at least includes your SBU ID and name,
something like the following is fine:

.. code-block:: md

    # Welcome to my repository for AMS 562

    * name: <your name>
    * SBU ID: <your id>

.. _soft_req_git_ssh:

Set up an SSH Key
-----------------

Using `Secure Shell <https://en.wikipedia.org/wiki/Secure_Shell>`_ is the
preferred way for using `Git`_. Follow
`this description <https://confluence.atlassian.com/bitbucket/set-up-an-ssh-key-728138079.html>`_
to setup an SSH key for your `Bitbucket`_ account.

.. note:: Keep your private key and **passphrase** secure!

.. _soft_req_vscode:

Code with `Visual Studio Code <https://code.visualstudio.com/>`_
================================================================

.. contents::
   :local:
   :backlinks: top

Using a decent editor is necessary, and develop with IDE-like environment is
extremely helpful. Among all existing popular editors, we have decided to
provide the `Visual Studio Code`_ that is developed by Microsoft. This editor
has been installed and properly configured in our container.

.. _soft_req_vscode_git:

Using :ref:`git <soft_req_git>` Inside VScode
---------------------------------------------

Using `Git`_ trough terminal might be confusing for people who first work. To
make things more consistent with our `Docker`_ setting, we find that using
`Git`_ through `Visual Studio Code`_ is extremely convenient. See
`this description <https://code.visualstudio.com/docs/editor/versioncontrol#_git-support>`_.

Notice that if you use `Git`_ through :ref:`SSH <soft_req_git_ssh>`, then you
need to run the following command inside the terminal of our
`container <https://github.com/compdatasci/ams562-desktop>`_:

.. code-block:: console

    $ ssh-add
    Enter passphrase for /path/to/.ssh/<your private key>:

Then enter your passphrase that your created for the key. This is done once
only.

Using Terminal Inside VScode
----------------------------

Using the integrated terminal of vscode is recommended, you can create/return
to a terminal session by type ``CTRL-```. By default, it will put you
at the *current working directory*, then you can invoke any commands inside
this integrated terminal.

.. tip::

    You can jump to a specific location of a file if the file is shown with
    absolute path. Therefore, it's convenient to pass in abs path of a file
    inside the integrated terminal. One easy way to do so is to add ```pwd`/``
    in front of your file.

.. code-block:: console

    $ g++ `pwd`/main.cpp
