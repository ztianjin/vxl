// This is brl/bbas/volm/desc/volm_desc_matcher.h
#ifndef volm_desc_matcher_h_
#define volm_desc_matcher_h_
//:
// \file
// \brief  A base class for matchers using volumetric descriptors
//
// \author Ozge C. Ozcanli
// \date May 29, 2013
//
// \verbatim
//  Modifications
//   <none yet>
// \endverbatim
//

#include <volm/desc/volm_desc.h>
#include <volm/desc/volm_desc_indexer.h>
#include <vbl/vbl_smart_ptr.h>
#include <vcl_string.h>
#include <volm/volm_geo_index.h>
#include <volm/volm_geo_index_sptr.h>

class volm_desc_matcher;
typedef vbl_smart_ptr<volm_desc_matcher> volm_desc_matcher_sptr;

class volm_desc_matcher : public vbl_ref_count
{
public:
  //: Default constructor
  volm_desc_matcher() {}

  //: Destructor
  virtual ~volm_desc_matcher() {}

  //: Comparison method to calculate the similarity of descriptor a and b, return a score from 0 to 1
  virtual float score(volm_desc_sptr const& a, volm_desc_sptr const& b) {return 0;}

  //: Create volumetric descriptor for the query image
  virtual volm_desc_sptr create_query_desc() { return 0;}

  //: Execute match algorithm implemented
  virtual bool matcher(volm_desc_sptr const& query,
                       vcl_string const& geo_hypo_folder,
                       vcl_string const& geo_index_folder,
                       unsigned const& tile_id) { return true; }

  //: write the matcher scores
  virtual bool write_out(vcl_string const& out_folder, unsigned const& tile_id) { return true; }

  //: get the name of the matcher
  vcl_string name() const { return name_; }

protected:
  vcl_string name_;
};

#endif  // volm_desc_matcher_h_