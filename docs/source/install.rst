Installing HESEB scanning tool
==============================

This page includes information about the needed packages to run the scan tool. 

Prerequisites
--------------

The following should be installed on the computer before running the scanning tool: 

* Linux redhat based OS (This work has been done under CentOS 7.4, however, there should be no reason to not work on other distributions)
* EPICS HESEB IOCs (for more info, refere to this link: Rami and Amor to add text here.)
* Python 3.9 
* QT 4.1.0 based on 5.9.7. 


Python virtual environment
---------------------------
The venv module of python provides support for creating **virtual environments** that is isolated from system site directories. Normally, each virtual environment has its own Python binary (which matches the version of the binary that was used to create this environment) and can have its own independent set of installed Python packages in its site directories. 

to install and create venv: 
::

	$ pip3.9 install virtualenv
	$ python3.9 -m venv /opt/DAQ/venv

to create alias of you environment: 
::

	$ vi ~/.bashrc

add the follwoing line to the file:
:: 

	alias p3='source /opt/DAQ/venv/bin/activate'

resource your bashrc: 
::

	source ~/.bashrc

Packages and libraries
-----------------------

The tool needs set of python packages and Qt libraries installed and configured.

Pyhon packages: 
...............

The list below contains the list of python packages needed for the scanning tool to run. After activating the python virtual environment (by typing **p3** in the terminal), you can use **pip** to install them in the virtual environment or you can copy this list in a text file (requirements.txt) and install them at once using this command (pip install -r requirements.txt)  

::
	
	bcrypt==3.2.0
	beautifulsoup4==4.11.1
	bs4==0.0.1
	certifi==2022.5.18.1
	cffi==1.15.0
	charset-normalizer==2.0.12
	colorama==0.4.4
	commonmark==0.9.1
	cryptography==36.0.2
	idna==3.3
	numpy==1.22.3
	paramiko==2.10.2
	pip-search==0.0.12
	progressbar==2.5
	pycparser==2.21
	pyepics==3.5.1
	Pygments==2.12.0
	PyNaCl==1.5.0
	PyQt5==5.15.6
	PyQt5-Qt5==5.15.2
	PyQt5-sip==12.9.1
	requests==2.27.1
	rich==12.4.1
	six==1.16.0
	soupsieve==2.3.2.post1
	urllib3==1.26.9


Qt and its libraries: 
.....................

	1. Request epics.repo from control group.
	2. Move the repo to: ``/etc/yum.repos.d``.
	3. Request the ``qt-creator-opensource-linux-x86_64-4.13.3.run``
	4. Install qt-creator-opensource-linux-x86_64-4.13.3.run. 
	5. Install epics-qt, qt5, qwt, or anything related to *qt* packages by ``yum`` command.
	6. Go to ``.bashrc`` and copy the following:

	::

		export EPICS_BASE='/opt/epics/base'
		export EPICS_HOST_ARCH=linux-x86_64
		export PATH=${PATH}:/opt/qtcreator-4.13.3/bin/
		export QWT_ROOT=/usr/local/qwt-6.1.3
		export QWT_INCLUDE_PATH=${QWT_ROOT}/include
		export QE_TARGET_DIR=/usr/local/epics-qt
		export PATH=${EPICS_BASE}/bin/$EPICS_HOST_ARCH:${QE_TARGET_DIR}/bin/${EPICS_HOST_ARCH}:/usr/lib64/qt5/bin:${PATH}
		export LD_LIBRARY_PATH=${EPICS_BASE}/lib/${EPICS_HOST_ARCH}:/usr/local/qwt-6.1.3/lib:${QE_TARGET_DIR}/lib/${EPICS_HOST_ARCH}:${QE_TARGET_DIR}/lib/${EPICS_HOST_ARCH}/designer
		export QT_PLUGIN_PATH=${QT_PLUGIN_PATH}:${QWT_ROOT}/plugins:$QE_TARGET_DIR/lib/$EPICS_HOST_ARCH

	6. ``source .bashrc`` 
	7. To validate your setup, create a new project and open the designer, you should get qwt and epics qt widgets shown.

Clone and run the scanning tool
--------------------------------

.. note:: Make sure that the python environment is activated before proceeding with this section 

The scanning tool (HESEBScanTool) is available on github. The most recent version can be found on this link: https://github.com/SESAME-Synchrotron/HESEBScanTool. To clone and run, launch your terminal then do the follwoing: 

::

	$ cd ~ 
	$ git clone git@github.com:SESAME-Synchrotron/HESEBScanTool.git
	$ cd HESEBScanTool
	$ python main.py --testingMode yes

.. warning:: If all is fine, you should see the GUI pops up, otherwise, error messages and alerts should be shown in the terminal.
	