/**
 * @file    importer.hpp
 * @ingroup voxy
 * @brief   Importer object for voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#ifndef VOXY_IMPORTER_HPP
#define VOXY_IMPORTER_HPP

#include <string>
#include <boost/filesystem>

#include "palette.hpp"
#include "scene.hpp"

namespace voxy{
  class importer{
  public:
    static voxy::palette load_palette_from_folder(std::string pFolderName){
      
    }
  private:
    importer(){}
  };
}
#endif //VOXY_IMPORTER_HPP
