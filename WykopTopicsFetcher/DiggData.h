//
// Created by defacto on 08.09.15.
//

#ifndef WYKOPTOPICSFETCHER_DIGGDATA_H
#define WYKOPTOPICSFETCHER_DIGGDATA_H

class DiggData {
    const std::string diggCount;
    const std::string diggTitle;
    const std::string diggLink;
    const std::string diggDescription;
    const std::string diggCommentsCount;
    const std::string diggTime;
public:

    DiggData(const std::string &diggCount, const std::string &diggTitle, const std::string &diggLink,
             const std::string &diggDescription, const std::string &diggCommentsCount, const std::string &diggTime)
            : diggTime(diggTime), diggCommentsCount(diggCommentsCount), diggDescription(diggDescription),
              diggCount(diggCount), diggTitle(diggTitle), diggLink(diggLink) { }

    const std::string getDiggCount() const;

    const std::string getDiggTitle() const;

    const std::string getDiggLink() const;

    const std::string getDiggDescription() const;

    const std::string getDiggCommentsCount() const;

    const std::string getDiggTime() const;
};

#endif //WYKOPTOPICSFETCHER_DIGGDATA_H
