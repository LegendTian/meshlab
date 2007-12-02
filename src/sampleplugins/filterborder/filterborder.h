/****************************************************************************
* MeshLab                                                           o o     *
* A versatile mesh processing toolbox                             o     o   *
*                                                                _   O  _   *
* Copyright(C) 2007                                                \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *   
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/
/****************************************************************************
  History

 $Log$
 Revision 1.1  2007/12/02 07:57:48  cignoni
 Added the new sample filter plugin that removes border faces


 *****************************************************************************/
#ifndef FILTERBORDERPLUGIN_H
#define FILTERBORDERPLUGIN_H

#include <QObject>
#include <QStringList>
#include <QString>

#include <meshlab/meshmodel.h>
#include <meshlab/interfaces.h>


class FilterBorder : public QObject, public MeshFilterInterface
{
	Q_OBJECT
	Q_INTERFACES(MeshFilterInterface)

		public:
	/* naming convention :
		 - FP -> Filter Plugin
		 - name of the plugin separated by _
	*/
	enum { 
    FP_REMOVE_BORDER_FACE, 
  } ;
	
	/* default values for standard parameters' values of the plugin actions */
	FilterBorder();
	~FilterBorder();

	virtual const QString filterName(FilterIDType filter);
	virtual const QString filterInfo(FilterIDType filter);
	virtual const PluginInfo &pluginInfo();

  virtual const FilterClass getClass(QAction *);
  virtual const int getRequirements(QAction *);

	virtual bool autoDialog(QAction *) {return true;}
	virtual void initParameterSet(QAction *,MeshModel &/*m*/, FilterParameterSet & /*parent*/);
	virtual bool applyFilter(QAction *filter, MeshModel &m, FilterParameterSet & /*parent*/, vcg::CallBackPos * cb) ;


	protected:
	
};


#endif
