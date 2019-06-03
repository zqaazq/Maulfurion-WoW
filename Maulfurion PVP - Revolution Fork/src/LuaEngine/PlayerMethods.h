/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef PLAYERMETHODS_H
#define PLAYERMETHODS_H

namespace LuaPlayer
{
    /* BOOLEAN */
#if (!defined(TBC) && !defined(CLASSIC))
    int CanTitanGrip(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanTitanGrip());
        return 1;
    }

    int HasTalent(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 talentId = Eluna::CHECKVAL<uint32>(L, 2);
        uint8 spec = Eluna::CHECKVAL<uint8>(L, 3);
        if (spec < MAX_TALENT_SPECS)
            return 1;
        Eluna::Push(L, player->HasTalent(talentId, spec));
        return 1;
    }

    int HasAchieved(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 achievementId = Eluna::CHECKVAL<uint32>(L, 2);
#ifndef TRINITY
        Eluna::Push(L, player->GetAchievementMgr().HasAchievement(achievementId));
#else
        Eluna::Push(L, player->HasAchieved(achievementId));
#endif
        return 1;
    }
#endif

    int HasQuest(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 quest = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->IsActiveQuest(quest));
        return 1;
    }

    int HasSkill(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasSkill(skill));
        return 1;
    }

    int HasSpell(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasSpell(id));
        return 1;
    }

    int HasAtLoginFlag(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 flag = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasAtLoginFlag((AtLoginFlags)flag));
        return 1;
    }

    int HasQuestForGO(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int32 entry = Eluna::CHECKVAL<int32>(L, 2);

        Eluna::Push(L, player->HasQuestForGO(entry));
        return 1;
    }

#ifndef CLASSIC
    int HasTitle(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);
        CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);
        if (titleInfo)
            Eluna::Push(L, player->HasTitle(titleInfo));
        return 1;
    }
#endif

    int HasItem(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 itemId = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 count = Eluna::CHECKVAL<uint32>(L, 3, 1);
        bool check_bank = Eluna::CHECKVAL<bool>(L, 4, false);
        Eluna::Push(L, player->HasItemCount(itemId, count, check_bank));
        return 1;
    }

    int HasQuestForItem(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasQuestForItem(entry));
        return 1;
    }

    int CanUseItem(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2, false);
        if (item)
            Eluna::Push(L, player->CanUseItem(item));
        else
        {
            uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
            const ItemTemplate* temp = eObjectMgr->GetItemTemplate(entry);
            if (temp)
                Eluna::Push(L, player->CanUseItem(temp));
            else
                Eluna::Push(L, EQUIP_ERR_ITEM_NOT_FOUND);
        }
        return 1;
    }

    int HasSpellCooldown(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasSpellCooldown(spellId));
        return 1;
    }

    int CanShareQuest(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->CanShareQuest(entry));
        return 1;
    }

    int CanSpeak(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanSpeak());
        return 1;
    }

    int CanUninviteFromGroup(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanUninviteFromGroup() == ERR_PARTY_RESULT_OK);
        return 1;
    }

#ifndef CLASSIC
    int CanFly(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanFly());
        return 1;
    }
#endif

#ifdef CLASSIC
    int GetHonorStoredKills(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool honorable = Eluna::CHECKVAL<bool>(L, 2, true);

        Eluna::Push(L, player->GetHonorStoredKills(honorable));
        return 0;
    }

    int GetRankPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetRankPoints());
        return 1;
    }

    int GetHonorLastWeekStandingPos(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetHonorLastWeekStandingPos());
        return 1;
    }
#endif

    int IsInWater(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->IsInWater());
        return 1;
    }

    int IsMoving(Eluna* /*E*/, lua_State* L, Player* player) // enable for unit when mangos support it
    {
        Eluna::Push(L, player->isMoving());
        return 1;
    }

#ifdef CLASSIC
    int UpdateHonor(Eluna* /*E*/, lua_State* L, Player* player)
    {
        player->UpdateHonor();
        return 0;
    }

    int ResetHonor(Eluna* /*E*/, lua_State* L, Player* player)
    {
        player->ResetHonor();
        return 0;
    }

    int ClearHonorInfo(Eluna* /*E*/, lua_State* L, Player* player)
    {
        player->ClearHonorInfo();
        return 0;
    }
#endif

#ifndef CLASSIC
    int IsFlying(Eluna* /*E*/, lua_State* L, Player* player) // enable for unit when mangos support it
    {
        Eluna::Push(L, player->IsFlying());
        return 1;
    }
#endif

    int IsInGroup(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, (player->GetGroup() != NULL));
        return 1;
    }

    int IsInGuild(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, (player->GetGuildId() != 0));
        return 1;
    }

    int IsGM(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        Eluna::Push(L, player->isGameMaster());
#else
        Eluna::Push(L, player->IsGameMaster());
#endif
        return 1;
    }

#ifndef CLASSIC
    int IsInArenaTeam(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 type = Eluna::CHECKVAL<uint32>(L, 2);
        if (type < MAX_ARENA_SLOT && player->GetArenaTeamId(type))
            Eluna::Push(L, true);
        else
            Eluna::Push(L, false);
        return 1;
    }
#endif

    int IsHorde(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, (player->GetTeam() == HORDE));
        return 1;
    }

    int IsAlliance(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, (player->GetTeam() == ALLIANCE));
        return 1;
    }

    int IsDND(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isDND());
        return 1;
    }

    int IsAFK(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isAFK());
        return 1;
    }

    int IsFalling(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->IsFalling());
        return 1;
    }

    int IsGroupVisibleFor(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);
        Eluna::Push(L, player->IsGroupVisibleFor(target));
        return 1;
    }

    int IsInSameRaidWith(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);
        Eluna::Push(L, player->IsInSameRaidWith(target));
        return 1;
    }

    int IsInSameGroupWith(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);
        Eluna::Push(L, player->IsInSameGroupWith(target));
        return 1;
    }

    int IsHonorOrXPTarget(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Unit* victim = Eluna::CHECKOBJ<Unit>(L, 2);

        Eluna::Push(L, player->isHonorOrXPTarget(victim));
        return 1;
    }

    int IsVisibleForPlayer(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);

        Eluna::Push(L, player->IsVisibleGloballyFor(target));
        return 1;
    }

    int IsGMVisible(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isGMVisible());
        return 1;
    }

    int IsTaxiCheater(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifdef MANGOS
        Eluna::Push(L, player->IsTaxiCheater());
#else
        Eluna::Push(L, player->isTaxiCheater());
#endif
        return 1;
    }

    int IsGMChat(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isGMChat());
        return 1;
    }

    int IsAcceptingWhispers(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isAcceptWhispers());
        return 1;
    }

    int IsRested(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isRested());
        return 1;
    }

    int InBattlegroundQueue(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        Eluna::Push(L, player->InBattleGroundQueue());
#else
        Eluna::Push(L, player->InBattlegroundQueue());
#endif
        return 1;
    }

#ifndef CLASSIC
    int InArena(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->InArena());
        return 1;
    }
#endif

    int InBattleground(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        Eluna::Push(L, player->InBattleGround());
#else
        Eluna::Push(L, player->InBattleground());
#endif
        return 1;
    }

    int CanBlock(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanBlock());
        return 1;
    }

    int CanParry(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanParry());
        return 1;
    }

    /*int HasReceivedQuestReward(Eluna* E, lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

    Eluna::Push(L, player->IsQuestRewarded(entry));
    return 1;
    }*/

    /*int IsOutdoorPvPActive(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->IsOutdoorPvPActive());
    return 1;
    }*/

    /*int IsImmuneToEnvironmentalDamage(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->IsImmuneToEnvironmentalDamage());
    return 1;
    }*/

    /*int InRandomLfgDungeon(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->inRandomLfgDungeon());
    return 1;
    }*/

    /*int IsUsingLfg(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->isUsingLfg());
    return 1;
    }*/

    /*int IsNeverVisible(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->IsNeverVisible());
    return 1;
    }*/

    /*int CanFlyInZone(Eluna* E, lua_State* L, Player* player)
    {
    uint32 mapid = Eluna::CHECKVAL<uint32>(L, 2);
    uint32 zone = Eluna::CHECKVAL<uint32>(L, 2);

    Eluna::Push(L, player->IsKnowHowFlyIn(mapid, zone));
    return 1;
    }*/

    /*int HasPendingBind(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->PendingHasPendingBind());
    return 1;
    }*/

    /*int IsARecruiter(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->GetSession()->IsARecruiter() || (player->GetSession()->GetRecruiterId() != 0));
    return 1;
    }*/

    /* GETTERS */
#if (!defined(TBC) && !defined(CLASSIC))
    int GetSpecsCount(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSpecsCount());
        return 1;
    }

    int GetActiveSpec(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetActiveSpec());
        return 1;
    }
#endif

#ifdef WOTLK
    int GetPhaseMaskForSpawn(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetPhaseMaskForSpawn());
        return 1;
    }
#endif

#ifndef CATA
#ifndef CLASSIC
    int GetArenaPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetArenaPoints());
        return 1;
    }

    int GetHonorPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetHonorPoints());
        return 1;
    }
#endif

    int GetShieldBlockValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetShieldBlockValue());
        return 1;
    }
#endif

    int GetSpellCooldownDelay(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, uint32(player->GetSpellCooldownDelay(spellId)));
        return 1;
    }

    int GetLatency(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetLatency());
        return 1;
    }

#ifdef TRINITY
    int GetChampioningFaction(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetChampioningFaction());
        return 1;
    }
#endif

    int GetOriginalSubGroup(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetOriginalSubGroup());
        return 1;
    }

    int GetOriginalGroup(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetOriginalGroup());
        return 1;
    }

    int GetNextRandomRaidMember(Eluna* /*E*/, lua_State* L, Player* player)
    {
        float radius = Eluna::CHECKVAL<float>(L, 2);

        Eluna::Push(L, player->GetNextRandomRaidMember(radius));
        return 1;
    }

    int GetSubGroup(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSubGroup());
        return 1;
    }

    int GetGroupInvite(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetGroupInvite());
        return 1;
    }

    int GetRestTime(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetRestTime());
        return 1;
    }

    int GetXPRestBonus(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 xp = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetXPRestBonus(xp));
        return 1;
    }

    int GetBattlegroundTypeId(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        Eluna::Push(L, player->GetBattleGroundTypeId());
#else
        Eluna::Push(L, player->GetBattlegroundTypeId());
#endif
        return 1;
    }

    int GetBattlegroundId(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        Eluna::Push(L, player->GetBattleGroundId());
#else
        Eluna::Push(L, player->GetBattlegroundId());
#endif
        return 1;
    }

    int GetReputationRank(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 faction = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetReputationRank(faction));
        return 1;
    }

    int GetDrunkValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetDrunkValue());
        return 1;
    }

    int GetSpellCooldowns(Eluna* /*E*/, lua_State* L, Player* player)
    {
        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        for (SpellCooldowns::const_iterator it = player->GetSpellCooldownMap().begin(); it != player->GetSpellCooldownMap().end(); ++it)
        {
            ++i;
            Eluna::Push(L, it->first);
            Eluna::Push(L, uint32(it->second.end));
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    int GetSkillTempBonusValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetSkillTempBonusValue(skill));
        return 1;
    }

    int GetSkillPermBonusValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetSkillPermBonusValue(skill));
        return 1;
    }

    int GetPureSkillValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetPureSkillValue(skill));
        return 1;
    }

    int GetBaseSkillValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetBaseSkillValue(skill));
        return 1;
    }

    int GetSkillValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetSkillValue(skill));
        return 1;
    }

    int GetPureMaxSkillValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetPureMaxSkillValue(skill));
        return 1;
    }

    int GetMaxSkillValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetMaxSkillValue(skill));
        return 1;
    }

    int GetManaBonusFromIntellect(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetManaBonusFromIntellect());
        return 1;
    }

    int GetHealthBonusFromStamina(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetHealthBonusFromStamina());
        return 1;
    }

    int GetDifficulty(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifdef TBC
        Eluna::Push(L, player->GetDifficulty());
#elif defined(CLASSIC)
        Eluna::Push(L, (Difficulty)0);
#else
        bool isRaid = Eluna::CHECKVAL<bool>(L, 2, true);
        Eluna::Push(L, player->GetDifficulty(isRaid));
#endif
        return 1;
    }

    int GetGuildRank(Eluna* /*E*/, lua_State* L, Player* player) // TODO: Move to Guild Methods
    {
        Eluna::Push(L, player->GetRank());
        return 1;
    }

    int GetFreeTalentPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetFreeTalentPoints());
        return 1;
    }

    int GetGuildName(Eluna* /*E*/, lua_State* L, Player* player)
    {
        if (!player->GetGuildId())
            return 1;
        Eluna::Push(L, eGuildMgr->GetGuildNameById(player->GetGuildId()));
        return 1;
    }

    int GetReputation(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 faction = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetReputationMgr().GetReputation(faction));
        return 1;
    }

    int GetComboTarget(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        Eluna::Push(L, player->GetMap()->GetUnit(player->GetComboTargetGuid()));
#else
        Eluna::Push(L, ObjectAccessor::GetUnit(*player, player->GetComboTarget()));
#endif
        return 1;
    }

    int GetComboPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetComboPoints());
        return 1;
    }

    int GetInGameTime(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetInGameTime());
        return 1;
    }

    int GetQuestStatus(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetQuestStatus(entry));
        return 1;
    }

    int GetQuestRewardStatus(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetQuestRewardStatus(questId));
        return 1;
    }

    int GetReqKillOrCastCurrentCount(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);
        int32 entry = Eluna::CHECKVAL<int32>(L, 3);

        Eluna::Push(L, player->GetReqKillOrCastCurrentCount(questId, entry));
        return 1;
    }

    int GetQuestLevel(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Quest* quest = Eluna::CHECKOBJ<Quest>(L, 2);

#ifndef TRINITY
        Eluna::Push(L, player->GetQuestLevelForPlayer(quest));
#else
        Eluna::Push(L, player->GetQuestLevel(quest));
#endif
        return 1;
    }

    int GetItemByEntry(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetItemByEntry(entry));
        return 1;
    }

    int GetEquippedItemBySlot(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint8 slot = Eluna::CHECKVAL<uint8>(L, 2);
        if (slot >= EQUIPMENT_SLOT_END)
            return 1;

        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        Eluna::Push(L, item);
        return 1;
    }

    int GetRestType(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetRestType());
        return 1;
    }

    int GetRestBonus(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetRestBonus());
        return 1;
    }

    int GiveLevel(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint8 level = Eluna::CHECKVAL<uint8>(L, 2);

        player->GiveLevel(level);
        return 0;
    }

    int GetChatTag(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetChatTag());
        return 1;
    }

    /**
     * Returns an item in given bag on given slot.
     *
     * <pre>
     * Possible and most commonly used combinations:
     *
     * bag = 255
     * slots 0-18 equipment
     * slots 19-22 equipped bag slots
     * slots 23-38 backpack
     * slots 39-66 bank main slots
     * slots 67-74 bank bag slots
     * slots 86-117 keyring
     *
     * bag = 19-22
     * slots 0-35 for equipped bags
     *
     * bag = 67-74
     * slots 0-35 for bank bags
     * </pre>
     *
     * @param uint8 bag : the bag the [Item] is in, you can get this with [Item:GetBagSlot]
     * @param uint8 slot : the slot the [Item] is in within the bag, you can get this with [Item:GetSlot]
     * @return [Item] item : [Item] or nil
     */
    int GetItemByPos(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint8 bag = Eluna::CHECKVAL<uint8>(L, 2);
        uint8 slot = Eluna::CHECKVAL<uint8>(L, 3);

        Eluna::Push(L, player->GetItemByPos(bag, slot));
        return 1;
    }

    int GetGossipTextId(Eluna* /*E*/, lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);
        Eluna::Push(L, player->GetGossipTextId(obj));
        return 1;
    }

    int GetSelection(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        Eluna::Push(L, player->GetMap()->GetUnit(player->GetSelectionGuid()));
#else
        Eluna::Push(L, player->GetSelectedUnit());
#endif
        return 1;
    }

    int GetGMRank(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetSecurity());
        return 1;
    }

    int GetCoinage(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetMoney());
        return 1;
    }

    int GetGuildId(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetGuildId());
        return 1;
    }

    int GetTeam(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetTeamId());
        return 1;
    }

    int GetItemCount(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int id = Eluna::CHECKVAL<int>(L, 2);
        bool checkinBank = Eluna::CHECKVAL<bool>(L, 3, false);
        Eluna::Push(L, player->GetItemCount(id, checkinBank));
        return 1;
    }

    int GetLifetimeKills(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
        return 1;
    }

    int GetPlayerIP(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetRemoteAddress());
        return 1;
    }

    int GetLevelPlayedTime(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetLevelPlayedTime());
        return 1;
    }

    int GetTotalPlayedTime(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetTotalPlayedTime());
        return 1;
    }

    int GetGuild(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, eGuildMgr->GetGuildById(player->GetGuildId()));
        return 1;
    }

    int GetGroup(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetGroup());
        return 1;
    }

    int GetAccountId(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetAccountId());
        return 1;
    }

    int GetAccountName(Eluna* /*E*/, lua_State* L, Player* player)
    {
        std::string accName;
        if (eAccountMgr->GetName(player->GetSession()->GetAccountId(), accName))
            Eluna::Push(L, accName);
        return 1;
    }

    int GetCorpse(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetCorpse());
        return 1;
    }

    int GetDbLocaleIndex(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetSessionDbLocaleIndex());
        return 1;
    }

    int GetDbcLocale(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetSessionDbcLocale());
        return 1;
    }

    /*int GetRecruiterId(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->GetSession()->GetRecruiterId());
    return 1;
    }*/

    /*int GetSelectedPlayer(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->GetSelectedPlayer());
    return 1;
    }*/

    /*int GetSelectedUnit(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, player->GetSelectedUnit());
    return 1;
    }*/

    /*int GetNearbyGameObject(Eluna* E, lua_State* L, Player* player)
    {
    Eluna::Push(L, ChatHandler(player->GetSession()).GetNearbyGameObject());
    return 1;
    }*/

    /* SETTERS */
    int SetPlayerLock(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);

        if (apply)
        {
            player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
            player->SetClientControl(player, 0);
        }
        else
        {
            player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
            player->SetClientControl(player, 1);
        }
        return 0;
    }

    int SetAtLoginFlag(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 flag = Eluna::CHECKVAL<uint32>(L, 2);

        player->SetAtLoginFlag((AtLoginFlags)flag);
        return 0;
    }

    int SetSheath(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 sheathed = Eluna::CHECKVAL<uint32>(L, 2);
        if (sheathed >= MAX_SHEATH_STATE)
            return 0;

        player->SetSheath((SheathState)sheathed);
        return 0;
    }

    int SetRestTime(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 value = Eluna::CHECKVAL<uint32>(L, 2);

        player->SetRestTime(value);
        return 0;
    }

    int SetDrunkValue(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint8 newDrunkValue = Eluna::CHECKVAL<uint8>(L, 2);

        player->SetDrunkValue(newDrunkValue);
        return 0;
    }

    int SetFactionForRace(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint8 race = Eluna::CHECKVAL<uint8>(L, 2);

        player->setFactionForRace(race);
        return 0;
    }

    int SetSkill(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint16 id = Eluna::CHECKVAL<uint16>(L, 2);
        uint16 step = Eluna::CHECKVAL<uint16>(L, 3);
        uint16 currVal = Eluna::CHECKVAL<uint16>(L, 4);
        uint16 maxVal = Eluna::CHECKVAL<uint16>(L, 5);

        player->SetSkill(id, step, currVal, maxVal);
        return 0;
    }

    int SetGuildRank(Eluna* /*E*/, lua_State* L, Player* player) // TODO: Move to Guild Methods
    {
        uint8 rank = Eluna::CHECKVAL<uint8>(L, 2);

        if (!player->GetGuildId())
            return 0;

        player->SetRank(rank);
        return 0;
    }

    int SetFreeTalentPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 points = Eluna::CHECKVAL<uint32>(L, 2);

        player->SetFreeTalentPoints(points);
#if (!defined(TBC) && !defined(CLASSIC))
        player->SendTalentsInfoData(false);
#endif
        return 0;
    }

    int SetReputation(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 faction = Eluna::CHECKVAL<uint32>(L, 2);
        int32 value = Eluna::CHECKVAL<int32>(L, 3);

        FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction);
        player->GetReputationMgr().SetReputation(factionEntry, value);
        return 0;
    }

    int SetQuestStatus(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 status = Eluna::CHECKVAL<uint32>(L, 3);
        if (status >= MAX_QUEST_STATUS)
            return 0;

        player->SetQuestStatus(entry, (QuestStatus)status);
        return 0;
    }

    int SetRestType(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int type = Eluna::CHECKVAL<int>(L, 2);

        player->SetRestType((RestType)type);
        return 0;
    }

    int SetRestBonus(Eluna* /*E*/, lua_State* L, Player* player)
    {
        float bonus = Eluna::CHECKVAL<float>(L, 2);

        player->SetRestBonus(bonus);
        return 0;
    }

    int SetAcceptWhispers(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetAcceptWhispers(on);
        return 0;
    }

    int SetPvPDeath(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetPvPDeath(on);
        return 0;
    }

    int SetGMVisible(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetGMVisible(on);
        return 0;
    }

    int SetTaxiCheat(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetTaxiCheater(on);
        return 0;
    }

    int SetGMChat(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetGMChat(on);
        return 0;
    }

    int SetGameMaster(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetGameMaster(on);
        return 0;
    }

    int SetGender(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 _gender = Eluna::CHECKVAL<uint32>(L, 2);

        Gender gender;
        switch (_gender)
        {
            case 0:
                gender = GENDER_MALE;
                break;
            case 1:
                gender = GENDER_FEMALE;
                break;
            default:
                return luaL_argerror(L, 2, "valid Gender expected");
        }

        player->SetByteValue(UNIT_FIELD_BYTES_0, 2, gender);
        player->SetByteValue(PLAYER_BYTES_3, 0, gender);
        player->InitDisplayIds();
        return 0;
    }

#ifndef CATA
#ifndef CLASSIC
    int SetArenaPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 arenaP = Eluna::CHECKVAL<uint32>(L, 2);
        player->SetArenaPoints(arenaP);
        return 0;
    }

    int SetHonorPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 honorP = Eluna::CHECKVAL<uint32>(L, 2);
        player->SetHonorPoints(honorP);
        return 0;
    }
#endif
#endif

#ifdef CLASSIC
    int SetHonorStoredKills(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 kills = Eluna::CHECKVAL<uint32>(L, 2);
        bool honorable = Eluna::CHECKVAL<bool>(L, 3, true);

        player->SetHonorStoredKills(kills, honorable);
        return 0;
    }

    int SetRankPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        float rankPoints = Eluna::CHECKVAL<float>(L, 2);

        player->SetRankPoints(rankPoints);
        return 0;
    }

    int SetHonorLastWeekStandingPos(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int32 standingPos = Eluna::CHECKVAL<int32>(L, 2);

        player->SetHonorLastWeekStandingPos(standingPos);
        return 0;
    }
#endif

    int SetLifetimeKills(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 val = Eluna::CHECKVAL<uint32>(L, 2);
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, val);
        return 0;
    }

    int SetCoinage(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 amt = Eluna::CHECKVAL<uint32>(L, 2);
        player->SetMoney(amt);
        return 0;
    }

    int SetBindPoint(Eluna* /*E*/, lua_State* L, Player* player)
    {
        float x = Eluna::CHECKVAL<float>(L, 2);
        float y = Eluna::CHECKVAL<float>(L, 3);
        float z = Eluna::CHECKVAL<float>(L, 4);
        uint32 mapId = Eluna::CHECKVAL<uint32>(L, 5);
        uint32 areaId = Eluna::CHECKVAL<uint32>(L, 6);

        WorldLocation loc(mapId, x, y, z);
#ifndef TRINITY
        player->SetHomebindToLocation(loc, areaId);
#else
        player->SetHomebind(loc, areaId);
#endif
        return 0;
    }

#ifndef CLASSIC
    int SetKnownTitle(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if (t)
            player->SetTitle(t, false);
        return 0;
    }
#endif

#ifndef TRINITY
    int SetFFA(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetFFAPvP(apply);
        return 0;
    }
#endif

    /*int SetMovement(Eluna* E, lua_State* L, Player* player)
    {
    int32 pType = Eluna::CHECKVAL<int32>(L, 2);

    player->SetMovement((PlayerMovementType)pType);
    return 0;
    }*/

    /* OTHER */
#if (!defined(TBC) && !defined(CLASSIC))
    int ResetPetTalents(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        Pet* pet = player->GetPet();
        Pet::resetTalentsForAllPetsOf(player, pet);
        if (pet)
            player->SendTalentsInfoData(true);
#else
        player->ResetPetTalents();
        player->SendTalentsInfoData(true);
#endif
        return 0;
    }

    int ResetAchievements(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifndef TRINITY
        player->GetAchievementMgr().Reset();
#else
        player->ResetAchievements();
#endif
        return 0;
    }
#endif

    int SendShowMailBox(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2, player->GET_GUID());

#if (defined(CLASSIC) || defined(TBC))
        WorldPacket data(CMSG_GET_MAIL_LIST, 8);
        data << uint64(guid);
        player->GetSession()->HandleGetMailList(data);
#else
        player->GetSession()->SendShowMailBox(ObjectGuid(guid));
#endif
        return 0;
    }

#ifndef CATA
#ifndef CLASSIC
    int ModifyArenaPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int32 amount = Eluna::CHECKVAL<int32>(L, 2);

        player->ModifyArenaPoints(amount);
        return 0;
    }

    int ModifyHonorPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int32 amount = Eluna::CHECKVAL<int32>(L, 2);

        player->ModifyHonorPoints(amount);
        return 0;
    }
#endif
#endif

    int SaveToDB(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->SaveToDB();
        return 0;
    }

    int SummonPlayer(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);
        uint32 map = Eluna::CHECKVAL<uint32>(L, 3);
        float x = Eluna::CHECKVAL<float>(L, 4);
        float y = Eluna::CHECKVAL<float>(L, 5);
        float z = Eluna::CHECKVAL<float>(L, 6);
        float zoneId = Eluna::CHECKVAL<float>(L, 7);
        uint32 delay = Eluna::CHECKVAL<uint32>(L, 8, 0);
        if (!MapManager::IsValidMapCoord(map, x, y, z))
            return 0;

        target->SetSummonPoint(map, x, y, z);
        WorldPacket data(SMSG_SUMMON_REQUEST, 8 + 4 + 4);
        data << uint64(player->GetGUIDLow());
        data << uint32(zoneId);
        data << uint32(delay ? delay* IN_MILLISECONDS : MAX_PLAYER_SUMMON_DELAY * IN_MILLISECONDS);
        target->GetSession()->SendPacket(&data);
        return 0;
    }

    int Mute(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 muteseconds = Eluna::CHECKVAL<uint32>(L, 2);
        /*const char* reason = luaL_checkstring(E, 2);*/ // Mangos does not have a reason field in database.

        uint64 muteTime = time(NULL) + muteseconds;
        player->GetSession()->m_muteTime = muteTime;
        LoginDatabase.PExecute("UPDATE account SET mutetime = " UI64FMTD " WHERE id = '%u'", muteTime, player->GetSession()->GetAccountId());
        return 0;
    }

    int CreateCorpse(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->CreateCorpse();
        return 0;
    }

    int RewardQuest(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Quest const* quest = eObjectMgr->GetQuestTemplate(entry);
        if (quest)
            player->RewardQuest(quest, 0, player);
        return 0;
    }

    int SendAuctionMenu(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Unit* unit = Eluna::CHECKOBJ<Unit>(L, 2);

#ifndef TRINITY
        AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit);
#else
        AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit->getFaction());
#endif
        if (!ahEntry)
            return 0;

        WorldPacket data(MSG_AUCTION_HELLO, 12);
        data << uint64(unit->GetGUIDLow());
        data << uint32(ahEntry->houseId);
        data << uint8(1);
        player->GetSession()->SendPacket(&data);
        return 0;
    }

    int SendTaxiMenu(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Creature* creature = Eluna::CHECKOBJ<Creature>(L, 2);

        player->GetSession()->SendTaxiMenu(creature);
        return 0;
    }

    int SendSpiritResurrect(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->GetSession()->SendSpiritResurrect();
        return 0;
    }

    int SendTabardVendorActivate(Eluna* /*E*/, lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);

        player->GetSession()->SendTabardVendorActivate(obj->GET_GUID());
        return 0;
    }

    int SendShowBank(Eluna* /*E*/, lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);

        player->GetSession()->SendShowBank(obj->GET_GUID());
        return 0;
    }

    int SendListInventory(Eluna* /*E*/, lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);

        player->GetSession()->SendListInventory(obj->GET_GUID());
        return 0;
    }

    int SendTrainerList(Eluna* /*E*/, lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);

        player->GetSession()->SendTrainerList(obj->GET_GUID());
        return 0;
    }

    int SendGuildInvite(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Player* plr = Eluna::CHECKOBJ<Player>(L, 2);

#ifndef TRINITY
        player->GetSession()->SendGuildInvite(plr);
#else
        if (Guild* guild = player->GetGuild())
            guild->HandleInviteMember(player->GetSession(), plr->GetName());
#endif
        return 0;
    }

    int LogoutPlayer(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool save = Eluna::CHECKVAL<bool>(L, 2, true);

        player->GetSession()->LogoutPlayer(save);
        return 0;
    }

    int RemoveFromBattlegroundRaid(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
#ifndef TRINITY
        player->RemoveFromBattleGroundRaid();
#else
        player->RemoveFromBattlegroundOrBattlefieldRaid();
#endif
        return 0;
    }

    int UnbindInstance(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 map = Eluna::CHECKVAL<uint32>(L, 2);
#ifndef CLASSIC
        uint32 difficulty = Eluna::CHECKVAL<uint32>(L, 3);

        if (difficulty < MAX_DIFFICULTY)
            player->UnbindInstance(map, (Difficulty)difficulty);
#else
        player->UnbindInstance(map);
#endif
        return 0;
    }

    int LeaveBattleground(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool teleToEntryPoint = Eluna::CHECKVAL<bool>(L, 2, true);

        player->LeaveBattleground(teleToEntryPoint);
        return 0;
    }

    int DurabilityRepair(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint16 position = Eluna::CHECKVAL<uint16>(L, 2);
        bool cost = Eluna::CHECKVAL<bool>(L, 3, true);
        float discountMod = Eluna::CHECKVAL<float>(L, 4);
        bool guildBank = Eluna::CHECKVAL<bool>(L, 5, false);

#ifdef CLASSIC
        Eluna::Push(L, player->DurabilityRepair(position, cost, discountMod));
#else
        Eluna::Push(L, player->DurabilityRepair(position, cost, discountMod, guildBank));
#endif
        return 1;
    }

    int DurabilityRepairAll(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool cost = Eluna::CHECKVAL<bool>(L, 2, true);
        float discountMod = Eluna::CHECKVAL<float>(L, 3, 1.0f);
        bool guildBank = Eluna::CHECKVAL<bool>(L, 4, false);

#ifdef CLASSIC
        Eluna::Push(L, player->DurabilityRepairAll(cost, discountMod));
#else
        Eluna::Push(L, player->DurabilityRepairAll(cost, discountMod, guildBank));
#endif
        return 1;
    }

    int DurabilityPointLossForEquipSlot(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int32 slot = Eluna::CHECKVAL<int32>(L, 2);

        if (slot >= EQUIPMENT_SLOT_START && slot < EQUIPMENT_SLOT_END)
            player->DurabilityPointLossForEquipSlot((EquipmentSlots)slot);
        return 0;
    }

    int DurabilityPointsLossAll(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int32 points = Eluna::CHECKVAL<int32>(L, 2);
        bool inventory = Eluna::CHECKVAL<bool>(L, 3, true);

        player->DurabilityPointsLossAll(points, inventory);
        return 0;
    }

    int DurabilityPointsLoss(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2);
        int32 points = Eluna::CHECKVAL<int32>(L, 3);

        player->DurabilityPointsLoss(item, points);
        return 0;
    }

    int DurabilityLoss(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2);
        double percent = Eluna::CHECKVAL<double>(L, 3);

        player->DurabilityLoss(item, percent);
        return 0;
    }

    int DurabilityLossAll(Eluna* /*E*/, lua_State* L, Player* player)
    {
        double percent = Eluna::CHECKVAL<double>(L, 2);
        bool inventory = Eluna::CHECKVAL<bool>(L, 3, true);

        player->DurabilityLossAll(percent, inventory);
        return 0;
    }

    int KillPlayer(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->KillPlayer();
        return 0;
    }

    int RemoveFromGroup(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        if (!player->GetGroup())
            return 0;

        player->RemoveFromGroup();
        return 0;
    }

    int ResetTalentsCost(Eluna* /*E*/, lua_State* L, Player* player)
    {
#ifdef CATA
        Eluna::Push(L, player->GetNextResetTalentsCost());
#else
#ifdef TRINITY
        Eluna::Push(L, player->ResetTalentsCost());
#else
        Eluna::Push(L, player->resetTalentsCost());
#endif
#endif
        return 1;
    }

    int ResetTalents(Eluna* /*E*/, lua_State* L, Player* player)
    {
        bool no_cost = Eluna::CHECKVAL<bool>(L, 2, true);

#ifdef CATA
        player->ResetTalents(no_cost);
#else
#ifdef TRINITY
        player->ResetTalents(no_cost);
#else
        player->resetTalents(no_cost);
#endif
#endif
#if (!defined(TBC) && !defined(CLASSIC))
        player->SendTalentsInfoData(false);
#endif
        return 0;
    }

    int RemoveSpell(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
        bool disabled = Eluna::CHECKVAL<bool>(L, 3, false);
        bool learn_low_rank = Eluna::CHECKVAL<bool>(L, 4, true);

#ifdef TRINITY
        player->RemoveSpell(entry, disabled, learn_low_rank);
#else
        player->removeSpell(entry, disabled, learn_low_rank);
#endif
        return 0;
    }

    int ClearComboPoints(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->ClearComboPoints();
        return 0;
    }

    int AddComboPoints(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        int8 count = Eluna::CHECKVAL<int8>(L, 3);

        player->AddComboPoints(target, count);
        return 0;
    }

    int TalkedToCreature(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
        Creature* creature = Eluna::CHECKOBJ<Creature>(L, 3);

        player->TalkedToCreature(entry, creature->GET_GUID());
        return 0;
    }

    int KilledMonsterCredit(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        player->KilledMonsterCredit(entry, player->GET_GUID());
        return 0;
    }

    int GroupEventHappens(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 3);

        player->GroupEventHappens(questId, obj);
        return 0;
    }

    int AreaExploredOrEventHappens(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);

        player->AreaExploredOrEventHappens(questId);
        return 0;
    }

    int FailQuest(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        player->FailQuest(entry);
        return 0;
    }

    int IncompleteQuest(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        player->IncompleteQuest(entry);
        return 0;
    }

    int CompleteQuest(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        player->CompleteQuest(entry);
        return 0;
    }

    int Whisper(Eluna* /*E*/, lua_State* L, Player* player)
    {
        std::string text = Eluna::CHECKVAL<std::string>(L, 2);
        uint32 lang = Eluna::CHECKVAL<uint32>(L, 3);
#ifdef TRINITY
        Player* receiver = Eluna::CHECKOBJ<Player>(L, 4);
#else
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 4);
#endif
#ifdef TRINITY
        player->Whisper(text, (Language)lang, receiver);
#else
        player->Whisper(text, lang, ObjectGuid(guid));
#endif
        return 0;
    }

    int TextEmote(Eluna* /*E*/, lua_State* L, Player* player)
    {
        std::string text = Eluna::CHECKVAL<std::string>(L, 2);

        player->TextEmote(text);
        return 0;
    }

    int Yell(Eluna* /*E*/, lua_State* L, Player* player)
    {
        std::string text = Eluna::CHECKVAL<std::string>(L, 2);
        uint32 lang = Eluna::CHECKVAL<uint32>(L, 3);
#ifdef TRINITY
        player->Yell(text, (Language)lang);
#else
        player->Yell(text, lang);
#endif
        return 0;
    }

    int Say(Eluna* /*E*/, lua_State* L, Player* player)
    {
        std::string text = Eluna::CHECKVAL<std::string>(L, 2);
        uint32 lang = Eluna::CHECKVAL<uint32>(L, 3);
#ifdef TRINITY
        player->Say(text, (Language)lang);
#else
        player->Say(text, lang);
#endif
        return 0;
    }

    int GiveXP(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 xp = Eluna::CHECKVAL<uint32>(L, 2);
        Unit* victim = Eluna::CHECKOBJ<Unit>(L, 3, false);

        player->GiveXP(xp, victim);
        return 0;
    }

    int ToggleDND(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->ToggleDND();
        return 0;
    }

    int ToggleAFK(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->ToggleAFK();
        return 0;
    }

    int EquipItem(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint16 dest = 0;
        Item* item = Eluna::CHECKOBJ<Item>(L, 2, false);
        uint32 slot = Eluna::CHECKVAL<uint32>(L, 3);

        if (slot >= INVENTORY_SLOT_BAG_END)
            return 1;

        if (!item)
        {
            uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
            item = Item::CreateItem(entry, 1, player);
            if (!item)
                return 1;

            InventoryResult result = player->CanEquipItem(slot, dest, item, false);
            if (result != EQUIP_ERR_OK)
            {
                delete item;
                return 1;
            }
            player->ItemAddedQuestCheck(entry, 1);
#if (!defined(TBC) && !defined(CLASSIC))
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, entry, 1);
#endif
        }
        else
        {
            InventoryResult result = player->CanEquipItem(slot, dest, item, false);
            if (result != EQUIP_ERR_OK)
                return 1;
            player->RemoveItem(item->GetBagSlot(), item->GetSlot(), true);
        }

        Eluna::Push(L, player->EquipItem(dest, item, true));
        return 1;
    }

    int CanEquipItem(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2, false);
        uint32 slot = Eluna::CHECKVAL<uint32>(L, 3);
        if (slot >= EQUIPMENT_SLOT_END)
        {
            Eluna::Push(L, false);
            return 1;
        }

        if (!item)
        {
            uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
            uint16 dest;
            InventoryResult msg = player->CanEquipNewItem(slot, dest, entry, false);
            if (msg != EQUIP_ERR_OK)
            {
                Eluna::Push(L, false);
                return 1;
            }
        }
        else
        {
            uint16 dest;
            InventoryResult msg = player->CanEquipItem(slot, dest, item, false);
            if (msg != EQUIP_ERR_OK)
            {
                Eluna::Push(L, false);
                return 1;
            }
        }
        Eluna::Push(L, true);
        return 1;
    }

#ifndef CLASSIC
    int UnsetKnownTitle(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if (t)
            player->SetTitle(t, true);
        return 0;
    }
#endif

    int AdvanceSkillsToMax(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->UpdateSkillsToMaxSkillsForLevel();
        return 0;
    }

    int AdvanceAllSkills(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 step = Eluna::CHECKVAL<uint32>(L, 2);

        if (!step)
            return 0;

        static const uint32 skillsArray[] = { SKILL_BOWS, SKILL_CROSSBOWS, SKILL_DAGGERS, SKILL_DEFENSE, SKILL_UNARMED, SKILL_GUNS, SKILL_AXES, SKILL_MACES, SKILL_SWORDS, SKILL_POLEARMS,
            SKILL_STAVES, SKILL_2H_AXES, SKILL_2H_MACES, SKILL_2H_SWORDS, SKILL_WANDS, SKILL_SHIELD, SKILL_FISHING, SKILL_MINING, SKILL_ENCHANTING, SKILL_BLACKSMITHING,
            SKILL_ALCHEMY, SKILL_HERBALISM, SKILL_ENGINEERING, SKILL_LEATHERWORKING, SKILL_LOCKPICKING, SKILL_SKINNING, SKILL_TAILORING,
#ifndef CLASSIC
            SKILL_JEWELCRAFTING,
#endif
#if (!defined(TBC) && !defined(CLASSIC))
            SKILL_INSCRIPTION,
#endif
        };
        static const uint32 skillsSize = sizeof(skillsArray) / sizeof(*skillsArray);

        for (uint32 i = 0; i < skillsSize; ++i)
        {
            if (player->HasSkill(skillsArray[i]))
                player->UpdateSkill(skillsArray[i], step);
        }
        return 0;
    }

    int AdvanceSkill(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 _skillId = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 _step = Eluna::CHECKVAL<uint32>(L, 3);
        if (_skillId && _step)
        {
            if (player->HasSkill(_skillId))
                player->UpdateSkill(_skillId, _step);
        }
        return 0;
    }

    int Teleport(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 mapId = Eluna::CHECKVAL<uint32>(L, 2);
        float x = Eluna::CHECKVAL<float>(L, 3);
        float y = Eluna::CHECKVAL<float>(L, 4);
        float z = Eluna::CHECKVAL<float>(L, 5);
        float o = Eluna::CHECKVAL<float>(L, 6);
#ifndef TRINITY
        if (player->IsTaxiFlying())
#else
        if (player->IsInFlight())
#endif
        {
            player->GetMotionMaster()->MovementExpired();
            player->m_taxi.ClearTaxiDestinations();
        }
        Eluna::Push(L, player->TeleportTo(mapId, x, y, z, o));
        return 1;
    }

    int AddLifetimeKills(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 val = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills + val);
        return 0;
    }

    int AddItem(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 itemId = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 itemCount = Eluna::CHECKVAL<uint32>(L, 3);

#ifndef TRINITY
        Eluna::Push(L, player->StoreNewItemInInventorySlot(itemId, itemCount));
#else
        uint32 noSpaceForCount = 0;
        ItemPosCountVec dest;
        InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, itemCount, &noSpaceForCount);
        if (msg != EQUIP_ERR_OK)
            itemCount -= noSpaceForCount;

        if (itemCount == 0 || dest.empty())
            return 1;

        Item* item = player->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
        if (item)
            player->SendNewItem(item, itemCount, true, false);
        Eluna::Push(L, item);
#endif
        return 1;
    }

    int RemoveItem(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2, false);
        uint32 itemCount = Eluna::CHECKVAL<uint32>(L, 3);
        if (!item)
        {
            uint32 itemId = Eluna::CHECKVAL<uint32>(L, 2);
            player->DestroyItemCount(itemId, itemCount, true);
        }
        else
        {
            bool all = itemCount >= item->GetCount();
            player->DestroyItemCount(item, itemCount, true);
            if (all)
                Eluna::CHECKOBJ<ElunaObject>(L, 2)->Invalidate();
        }
        return 0;
    }

    int RemoveLifetimeKills(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 val = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
        if (val > currentKills)
            val = currentKills;
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills - val);
        return 0;
    }

    int ResetSpellCooldown(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);
        bool update = Eluna::CHECKVAL<bool>(L, 3, true);
        player->RemoveSpellCooldown(spellId, update);
        return 0;
    }

    int ResetTypeCooldowns(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 category = Eluna::CHECKVAL<uint32>(L, 2);
        bool update = Eluna::CHECKVAL<bool>(L, 3, true);
        player->RemoveSpellCategoryCooldown(category, update);
        return 0;
    }

    int ResetAllCooldowns(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->RemoveAllSpellCooldown();
        return 0;
    }

    int SendClearCooldowns(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 3);

        player->SendClearCooldown(spellId, target);
        return 0;
    }

    int SendBroadcastMessage(Eluna* /*E*/, lua_State* L, Player* player)
    {
        const char* message = Eluna::CHECKVAL<const char*>(L, 2);
        if (std::string(message).length() > 0)
            ChatHandler(player->GetSession()).SendSysMessage(message);
        return 0;
    }

    int SendAreaTriggerMessage(Eluna* /*E*/, lua_State* L, Player* player)
    {
        std::string msg = Eluna::CHECKVAL<std::string>(L, 2);
        if (msg.length() > 0)
            player->GetSession()->SendAreaTriggerMessage("%s", msg.c_str());
        return 0;
    }

    int SendNotification(Eluna* /*E*/, lua_State* L, Player* player)
    {
        std::string msg = Eluna::CHECKVAL<std::string>(L, 2);
        if (msg.length() > 0)
            player->GetSession()->SendNotification("%s", msg.c_str());
        return 0;
    }

    int SendPacket(Eluna* /*E*/, lua_State* L, Player* player)
    {
        WorldPacket* data = Eluna::CHECKOBJ<WorldPacket>(L, 2);
        bool selfOnly = Eluna::CHECKVAL<bool>(L, 3, true);
        if (selfOnly)
            player->GetSession()->SendPacket(data);
        else
            player->SendMessageToSet(data, true);
        return 0;
    }

    int SendAddonMessage(Eluna* /*E*/, lua_State* L, Player* player)
    {
        std::string prefix = Eluna::CHECKVAL<std::string>(L, 2);
        std::string message = Eluna::CHECKVAL<std::string>(L, 3);
        uint8 channel = Eluna::CHECKVAL<uint8>(L, 4);
        Player* receiver = Eluna::CHECKOBJ<Player>(L, 5);

        std::string fullmsg = prefix + "\t" + message;

        WorldPacket data(SMSG_MESSAGECHAT, 100);
        data << uint8(channel);
        data << int32(LANG_ADDON);
        data << uint64(player->GET_GUID());
#ifndef CLASSIC
        data << uint32(0);
        data << uint64(receiver->GET_GUID());
#endif
        data << uint32(fullmsg.length() + 1);
        data << fullmsg;
        data << uint8(0);
        receiver->GetSession()->SendPacket(&data);
        return 0;
    }

    int SendVendorWindow(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Unit* sendTo = Eluna::CHECKOBJ<Unit>(L, 2);
        player->GetSession()->SendListInventory(sendTo->GET_GUID());
        return 0;
    }

    int KickPlayer(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->GetSession()->KickPlayer();
        return 0;
    }

    int ModifyMoney(Eluna* /*E*/, lua_State* L, Player* player)
    {
        int32 amt = Eluna::CHECKVAL<int32>(L, 2);

        player->ModifyMoney(amt);
        return 1;
    }

    int LearnSpell(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);

#ifdef TRINITY
        player->LearnSpell(id, false);
#else
        player->learnSpell(id, false);
#endif
        return 0;
    }

    int ResurrectPlayer(Eluna* /*E*/, lua_State* L, Player* player)
    {
        float percent = Eluna::CHECKVAL<float>(L, 2, 100.0f);
        bool sickness = Eluna::CHECKVAL<bool>(L, 3, false);
        player->ResurrectPlayer(percent, sickness);
        player->SpawnCorpseBones();
        return 0;
    }

    int GossipMenuAddItem(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 _icon = Eluna::CHECKVAL<uint32>(L, 2);
        const char* msg = Eluna::CHECKVAL<const char*>(L, 3);
        uint32 _sender = Eluna::CHECKVAL<uint32>(L, 4);
        uint32 _intid = Eluna::CHECKVAL<uint32>(L, 5);
        bool _code = Eluna::CHECKVAL<bool>(L, 6, false);
        const char* _promptMsg = Eluna::CHECKVAL<const char*>(L, 7, "");
        uint32 _money = Eluna::CHECKVAL<uint32>(L, 8, 0);
#ifndef TRINITY
#ifndef CLASSIC
        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(_icon, msg, _sender, _intid, _promptMsg, _money, _code);
#else
        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(_icon, msg, _sender, _intid, _promptMsg, _code);
#endif
#else
        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, _icon, msg, _sender, _intid, _promptMsg, _money, _code);
#endif
        return 0;
    }

    int GossipComplete(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
#ifndef TRINITY
        player->PlayerTalkClass->CloseGossip();
#else
        player->PlayerTalkClass->SendCloseGossip();
#endif
        return 0;
    }

    int GossipSendMenu(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 _npcText = Eluna::CHECKVAL<uint32>(L, 2);
        WorldObject* sender = Eluna::CHECKOBJ<WorldObject>(L, 3);
        if (sender->GetTypeId() == TYPEID_PLAYER)
        {
            uint32 menu_id = Eluna::CHECKVAL<uint32>(L, 4);
            player->PlayerTalkClass->GetGossipMenu().SetMenuId(menu_id);
        }
        player->PlayerTalkClass->SendGossipMenu(_npcText, sender->GET_GUID());
        return 0;
    }

    int GossipClearMenu(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->PlayerTalkClass->ClearMenus();
        return 0;
    }

    int PlaySoundToPlayer(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 soundId = Eluna::CHECKVAL<uint32>(L, 2);
        SoundEntriesEntry const* soundEntry = sSoundEntriesStore.LookupEntry(soundId);
        if (!soundEntry)
            return 0;

        player->PlayDirectSound(soundId, player);
        return 0;
    }

    int StartTaxi(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 pathId = Eluna::CHECKVAL<uint32>(L, 2);

        if (pathId >= sTaxiPathNodesByPath.size())
            return 0;

        TaxiPathNodeList const& path = sTaxiPathNodesByPath[pathId];
        if (path.size() < 2)
            return 0;

        std::vector<uint32> nodes;
        nodes.resize(2);
        nodes[0] = path[0].index;
        nodes[1] = path[path.size() - 1].index;

        player->ActivateTaxiPathTo(nodes);
        return 0;
    }

    int GossipSendPOI(Eluna* /*E*/, lua_State* L, Player* player)
    {
        float x = Eluna::CHECKVAL<float>(L, 2);
        float y = Eluna::CHECKVAL<float>(L, 3);
        uint32 icon = Eluna::CHECKVAL<uint32>(L, 4);
        uint32 flags = Eluna::CHECKVAL<uint32>(L, 5);
        uint32 data = Eluna::CHECKVAL<uint32>(L, 6);
        std::string iconText = Eluna::CHECKVAL<std::string>(L, 6);

        WorldPacket packet(SMSG_GOSSIP_POI, 4 + 4 + 4 + 4 + 4 + 10);
        packet << flags;
        packet << x;
        packet << y;
        packet << icon;
        packet << data;
        packet << iconText;
        player->GetSession()->SendPacket(&packet);
        return 0;
    }

    int GossipAddQuests(Eluna* /*E*/, lua_State* L, Player* player)
    {
        WorldObject* source = Eluna::CHECKOBJ<WorldObject>(L, 2);

        if (source->GetTypeId() == TYPEID_UNIT)
        {
            if (source->GetUInt32Value(UNIT_NPC_FLAGS) & UNIT_NPC_FLAG_QUESTGIVER)
                player->PrepareQuestMenu(source->GET_GUID());
        }
        else if (source->GetTypeId() == TYPEID_GAMEOBJECT)
        {
            if (source->ToGameObject()->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
                player->PrepareQuestMenu(source->GET_GUID());
        }
        return 0;
    }

    int SendQuestTemplate(Eluna* /*E*/, lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);
        bool activeAccept = Eluna::CHECKVAL<bool>(L, 3, true);

        Quest const* quest = eObjectMgr->GetQuestTemplate(questId);
        if (!quest)
            return 0;

        player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, player->GET_GUID(), activeAccept);
        return 0;
    }

    int SpawnBones(Eluna* /*E*/, lua_State* /*L*/, Player* player)
    {
        player->SpawnCorpseBones();
        return 0;
    }

    int RemovedInsignia(Eluna* /*E*/, lua_State* L, Player* player)
    {
        Player* looter = Eluna::CHECKOBJ<Player>(L, 2);
        player->RemovedInsignia(looter);
        return 0;
    }

    /*int BindToInstance(Eluna* E, lua_State* L, Player* player)
    {
    player->BindToInstance();
    return 0;
    }*/

    /*int AddTalent(Eluna* E, lua_State* L, Player* player)
    {
    uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);
    uint8 spec = Eluna::CHECKVAL<uint8>(L, 3);
    bool learning = Eluna::CHECKVAL<bool>(L, 4, true);
    if (spec >= MAX_TALENT_SPECS)
    Eluna::Push(L, false);
    else
    Eluna::Push(L, player->AddTalent(spellId, spec, learning));
    return 1;
    }*/

    /*int GainSpellComboPoints(Eluna* E, lua_State* L, Player* player)
    {
    int8 count = Eluna::CHECKVAL<int8>(L, 2);

    player->GainSpellComboPoints(count);
    return 0;
    }*/

    /*int KillGOCredit(Eluna* E, lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
    uint64 guid = Eluna::CHECKVAL<uint64>(L, 3);
    player->KillCreditGO(entry, guid);
    return 0;
    }*/

    /*int KilledPlayerCredit(Eluna* E, lua_State* L, Player* player)
    {
    player->KilledPlayerCredit();
    return 0;
    }*/

    /*int RemoveRewardedQuest(Eluna* E, lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

    player->RemoveRewardedQuest(entry);
    return 0;
    }*/

    /*int RemoveActiveQuest(Eluna* E, lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

    player->RemoveActiveQuest(entry);
    return 0;
    }*/

    /*int SummonPet(Eluna* E, lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
    float x = Eluna::CHECKVAL<float>(L, 3);
    float y = Eluna::CHECKVAL<float>(L, 4);
    float z = Eluna::CHECKVAL<float>(L, 5);
    float o = Eluna::CHECKVAL<float>(L, 6);
    uint32 petType = Eluna::CHECKVAL<uint32>(L, 7);
    uint32 despwtime = Eluna::CHECKVAL<uint32>(L, 8);

    if (petType >= MAX_PET_TYPE)
    return 0;

    player->SummonPet(entry, x, y, z, o, (PetType)petType, despwtime);
    return 0;
    }*/

    /*int RemovePet(Eluna* E, lua_State* L, Player* player)
    {
    int mode = Eluna::CHECKVAL<int>(L, 2, PET_SAVE_AS_DELETED);
    bool returnreagent = Eluna::CHECKVAL<bool>(L, 2, false);

    if (!player->GetPet())
    return 0;

    player->RemovePet(player->GetPet(), (PetSaveMode)mode, returnreagent);
    return 0;
    }*/
};
#endif
