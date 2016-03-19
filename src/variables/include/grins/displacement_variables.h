//-----------------------------------------------------------------------bl-
//--------------------------------------------------------------------------
//
// GRINS - General Reacting Incompressible Navier-Stokes
//
// Copyright (C) 2014-2015 Paul T. Bauman, Roy H. Stogner
// Copyright (C) 2010-2013 The PECOS Development Team
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the Version 2.1 GNU Lesser General
// Public License as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc. 51 Franklin Street, Fifth Floor,
// Boston, MA  02110-1301  USA
//
//-----------------------------------------------------------------------el-

#ifndef GRINS_DISPLACEMENT_VARIABLES_H
#define GRINS_DISPLACEMENT_VARIABLES_H

// libMesh
#include "libmesh/libmesh_common.h"

// GRINS
#include "grins/variables_base.h"
#include "grins/variables_parsing.h"

namespace GRINS
{
  class DisplacementVariables : public VariablesBase
  {
  public:

    DisplacementVariables( const GetPot& input );
    virtual ~DisplacementVariables(){};

    //! Initialize System variables
    /*!
     * Additional arguments specify whether the spatial mesh is really 2D or 3D.
     * This is needed for cases such as a 1D beam in 2D (is_2D = true) or 3D (is_3D = true)
     * space or 2D shell manifolds in 3D (is_3D = true).
     */
    virtual void init_vars( libMesh::FEMSystem* system );

    bool have_v() const;
    bool have_w() const;

    VariableIndex u() const;
    VariableIndex v() const;
    VariableIndex w() const;

    const std::string& u_name() const;
    const std::string& v_name() const;
    const std::string& w_name() const;

  protected:

    std::string subsection() const
    { return VariablesParsing::displacement_section(); }

    bool _have_v;
    bool _have_w;

    unsigned int _u_idx, _v_idx, _w_idx;

  };

  inline
  VariableIndex DisplacementVariables::u() const
  {
    return this->_vars[_u_idx];
  }

  inline
  VariableIndex DisplacementVariables::v() const
  {
    libmesh_assert(_have_v);
    return this->_vars[_v_idx];
  }

  inline
  VariableIndex DisplacementVariables::w() const
  {
    libmesh_assert(_have_w);
    return this->_vars[_w_idx];
  }

  inline
  bool DisplacementVariables::have_v() const
  {
    return _have_v;
  }

  inline
  bool DisplacementVariables::have_w() const
  {
    return _have_w;
  }

  inline
  const std::string& DisplacementVariables::u_name() const
  {
    return this->_var_names[_u_idx];
  }

  inline
  const std::string& DisplacementVariables::v_name() const
  {
    return this->_var_names[_v_idx];
  }

  inline
  const std::string& DisplacementVariables::w_name() const
  {
    return this->_var_names[_w_idx];
  }

} // end namespace GRINS

#endif // GRINS_DISPLACEMENT_VARIABLES_H