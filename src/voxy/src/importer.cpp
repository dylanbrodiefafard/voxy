/**
 * @file    importer.cpp
 * @ingroup voxy
 * @brief   Importer object for voxy library.
 *
 * Copyright (c) 2017 Dylan Brodie Fafard (dylan.brodie.fafard@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <boost/filesystem.hpp>
#include <boost/range.hpp>
#include <boost/log/trivial.hpp>
#include <experimental/optional>

#include "importer.hpp"
#include "palette.hpp"
#include "scene.hpp"

static std::experimental::optional<voxy::palette>
voxy::importer::load_palette_from_folder(std::string pFolderName) {
  if (!boost::filesystem::is_directory(pFolderName)) {
    BOOST_LOG_TRIVIAL(error) << "Failed to read directory: " << pFolderName;
    return std::experimental::optional<voxy::palette>();
  }

  for (auto &entry :
       boost::make_iterator_range(boost::filesystem::directory_iterator(pFolderName), {}))
    ;
}
