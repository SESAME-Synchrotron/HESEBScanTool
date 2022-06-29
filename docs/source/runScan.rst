Run experiment and collect data 
===============================
.. note:: All beamline EPICS IOCs should be up and running before using the scanning tool.

.. note:: In order to run the scanning tool, you need to activate python environment that you have already setup. 

The scanning tool home directory is located in the home directory of the control user. To access it: 
::

	$ cd ~ 
	$ cd HESEBScanTool
	

to run the scanning tool: 
::

	$ python main.py 

the main function will validate and execute some procedures and functions, if all is fine GUI will appear: 

.. figure:: /images/start.png
   :align: center
   :alt: first popup GUI

   *Figure 1: First popup GUI that allows you to choose experiment type*

.. warning:: if some PVs are disconnected, the scanning tool will show them in "red" color instead of green as shown ubove and this will cause the tool to not run!!.

From the GUI above you can choose the experiment type. Choose **Users Experiment** if there is a schedule beam time for an accepted proposal. By choosing "Users Experiment", the scan tool will: 

* Ask you to provide the proposal number. 
* Validate whether the provided proposal number is correct and valid for this beam time. 
* If the validation result is okay, the tool will import the proposal metadata and include them in the experimental file. If not, user will be alerted!!

.. note:: The scanning tool is already integrated with the users database. All validation and metadata importing processes are done through such integration. 

On the other hand, choosing **Local Experiment** is meant for beamline scientist to run InHouse research experiments. 

.. error:: Users with scheduled beamtime are requested to choose **Users Experiment** in order to keep their experimental data consistent with the proposal metadata.



